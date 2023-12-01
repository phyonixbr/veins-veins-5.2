//
// Copyright (C) 2016 David Eckhoff <david.eckhoff@fau.de>
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

#include "veins/modules/application/traci/TraCIDemoRSU11p.h"

#include "veins/modules/application/traci/TraCIDemo11pMessage_m.h"
#include "messageModuloConquista_m.h"

using namespace veins;

Define_Module(veins::TraCIDemoRSU11p);

void TraCIDemoRSU11p::initialize(int stage)
{ //Método de Inicialização da RSU
    BaseApplLayer::initialize(stage);
    periodoGestaoBeacon = 50; //Definir aqui o tempo de sincronização com o módulo de gestão

    if (stage == 0) { //Estágio de Criação da RSU
        eventoEnviaBInf0rmacoeGestao = new cMessage("msg Gestão Beacon evt",SEND_MSG_GESTAO);
        eventoEnviaBeacon= new cMessage("beacon Platoon evt",
                  SEND_BEACON);


    }
    else if (stage == 1) {//Estági do início da transmissão

        tempoInicioMsgGestaoBeacon = simTime().dbl() + periodoGestaoBeacon;

        scheduleAt(tempoInicioMsgGestaoBeacon, eventoEnviaBInf0rmacoeGestao);

    }

}

//Método que trata as mensagens manipuladas pelo própio dispositivo e mensagens recebidas ou enviadas via rede
void TraCIDemoRSU11p::handleSelfMsg(cMessage* msg)
{
  // double timeSimulator = simTime().dbl();

   if (msg->getKind() == SEND_MSG_GESTAO)
   {
       enviaDadosParaGestao();
       tempoInicioMsgGestaoBeacon = simTime().dbl() + periodoGestaoBeacon;
       scheduleAt(tempoInicioMsgGestaoBeacon, eventoEnviaBInf0rmacoeGestao);
   }


}

void TraCIDemoRSU11p::enviaDadosParaGestao()
{
    int NumBeaconRecebidos;
    int NumbeaconAux;

    std::cout<<"\\--->>>>Evento de Envio de Dados  Periodo="<<simTime().dbl();

    listaAux.clear();
    listaAux = listaBeaconsRecebidos;  ///lista de msg recebidas em um período
    //Início do Semaforo
    mtx.lock();

    NumBeaconRecebidos = listaBeaconsRecebidos.size();
    listaBeaconsRecebidos.clear();
    NumbeaconAux = listaAux.size();


    std::cout << "\n $$$$$$$ Dados Disseminados para modulos de controle  BeaconRecebidos ="<<listaBeaconsRecebidos.size();
    std::cout<< " NumBeacon Aux"<<listaAux.size();




    //Fim do Semaforo
    mtx.unlock();

    //colocar o envio dos dados para o Docker dentro deste método
    enviaDadosViaDocker(NumBeaconRecebidos);

}


void TraCIDemoRSU11p::enviaDadosViaDocker(int pNumBeacomCarro)
{

}


void TraCIDemoRSU11p::onWSA(DemoServiceAdvertisment* wsa)
{
    // if this RSU receives a WSA for service 42, it will tune to the chan
    if (wsa->getPsid() == 42) {
        mac->changeServiceChannel(static_cast<Channel>(wsa->getTargetChannel()));
    }
}
void TraCIDemoRSU11p::onBSM(DemoSafetyMessage* bsm)
{
    //recebeBeacon(bsm);
};

void TraCIDemoRSU11p::onWSM(BaseFrame1609_4* frame)
{

    if (MessageModuloConquista* wsm = check_and_cast<MessageModuloConquista*>(frame))
    {
        recebeBeacon(wsm);

    }

    // this rsu repeats the received traffic update in 2 seconds plus some random delay
    //sendDelayedDown(wsm->dup(), 2 + uniform(0.01, 0.2));
    //wsm->getPsid();



}


void TraCIDemoRSU11p::recebeBeacon(MessageModuloConquista* pMsg)
{
   // Address::L2Type senderId;
    int idVehiculo  = pMsg->getIdVeiculo();


     std::cout<<"\Beacon Id="<<pMsg->getId()<<" Veiculo = "<< idVehiculo;

   if (existeVeiculoNaListaDeBeacons(idVehiculo))
    {
        std::cout<< "\n Já existe Veiculo";
    }
    else
    {
      listaBeaconsRecebidos.push_back(pMsg);
    }

}




bool TraCIDemoRSU11p::existeVeiculoNaListaDeBeacons(int pIdVeiculo)
{
    bool resultado = false;
    for (int i = 0; i< listaBeaconsRecebidos.size(); i++)    {
        if (listaBeaconsRecebidos[i]->getId()==  pIdVeiculo)
           return true;

    }
    return resultado;

}










