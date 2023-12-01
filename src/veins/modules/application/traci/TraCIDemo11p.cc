//
// Copyright (C) 2006-2011 Christoph Sommer <christoph.sommer@uibk.ac.at>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "veins/modules/application/traci/TraCIDemo11p.h"

#include "veins/modules/application/traci/TraCIDemo11pMessage_m.h"

using namespace veins;

Define_Module(veins::TraCIDemo11p);

void TraCIDemo11p::initialize(int stage)
{
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {
        sentMessage = false;
        lastDroveAt = simTime();
        currentSubscribedServiceId = -1;
        idVeiculo = incrementaVeiculo();
        eventoEnviaBeacon= new cMessage("beacon Platoon evt",
                         SEND_BEACON);
         std::cout<< "\n IdVeiculoLocal"<<idVeiculo;
    }
    else if(stage == 1)
    {

        scheduleAt((simTime().dbl() + beaconInterval + getAtraso(true)), eventoEnviaBeacon);

    }
}

double TraCIDemo11p::getAtraso(bool utilizaAtrasoRandomico)
{
     //2  => 0.00022222 ; 3 => 0.0003333atraso = idCar*0.0001111;  //2  => 0.00022222 ; 3 => 0.0003333atraso = idCar*0.0001111;  //2  => 0.00022222 ; 3 => 0.0003333
    simtime_t atraso;
    srand(idVeiculo);
    if (utilizaAtrasoRandomico)
    {
        atraso = rand() % 99; //pega um intervalo entre 0 e 99
        atraso = atraso / 1000; //para dar milesimos de segundos
        return  atraso.dbl() + idVeiculo*0.0001111;
    }
    else
    {
      atraso = idVeiculo*0.00111;  //idCar=2  => 0.00022222 ; 3 => 0.0003333
      return  atraso.dbl();
    }
}

void TraCIDemo11p::onWSA(DemoServiceAdvertisment* wsa)
{
    if (currentSubscribedServiceId == -1) {
        mac->changeServiceChannel(static_cast<Channel>(wsa->getTargetChannel()));
        currentSubscribedServiceId = wsa->getPsid();
        if (currentOfferedServiceId != wsa->getPsid()) {
            stopService();
            startService(static_cast<Channel>(wsa->getTargetChannel()), wsa->getPsid(), "Mirrored Traffic Service");
        }
    }
}

void TraCIDemo11p::onWSM(BaseFrame1609_4* frame)
{
    TraCIDemo11pMessage* wsm = check_and_cast<TraCIDemo11pMessage*>(frame);

    findHost()->getDisplayString().setTagArg("i", 1, "green");

    if (mobility->getRoadId()[0] != ':') traciVehicle->changeRoute(wsm->getDemoData(), 9999);
    if (!sentMessage) {
        sentMessage = true;
        // repeat the received traffic update once in 2 seconds plus some random delay
        wsm->setSenderAddress(myId);
        wsm->setSerial(3);
        scheduleAt(simTime() + 2 + uniform(0.01, 0.2), wsm->dup());
    }
}

void TraCIDemo11p::handleSelfMsg(cMessage* msg)
{
    if (msg->getKind() == SEND_BEACON)
    {
        MessageModuloConquista* beaconConquista = new MessageModuloConquista();
        beaconConquista->setIdVeiculo(idVeiculo);
        populateWSM(beaconConquista);
        sendDown(beaconConquista);
        scheduleAt(simTime().dbl() + beaconInterval, eventoEnviaBeacon);
    }
    else
    {
        DemoBaseApplLayer::handleSelfMsg(msg);
    }
}

void TraCIDemo11p::handlePositionUpdate(cObject* obj)
{
    DemoBaseApplLayer::handlePositionUpdate(obj);

    // stopped for for at least 10s?
    if (mobility->getSpeed() < 1) {
        if (simTime() - lastDroveAt >= 10 && sentMessage == false) {
            findHost()->getDisplayString().setTagArg("i", 1, "red");
            sentMessage = true;

            TraCIDemo11pMessage* wsm = new TraCIDemo11pMessage();
            populateWSM(wsm);
            wsm->setDemoData(mobility->getRoadId().c_str());


            // host is standing still due to crash
            if (dataOnSch) {
                startService(Channel::sch2, 42, "Traffic Information Service");
                // started service and server advertising, schedule message to self to send later
                scheduleAt(computeAsynchronousSendingTime(1, ChannelType::service), wsm);
            }
            else {
                // send right away on CCH, because channel switching is disabled
                sendDown(wsm);
            }
        }
    }
    else {
        lastDroveAt = simTime();
    }
}

int TraCIDemo11p::incrementaVeiculo()
{
    static int contVeiculo;
    contVeiculo++;
    return contVeiculo;
}
