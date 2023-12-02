//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef __VEINS_VISOESPLATOON_H_
#define __VEINS_VISOESPLATOON_H_
#include "veins/modules/application/ieee80211p/DemoBaseApplLayer.h"
#include <omnetpp.h>
#include "VisoesPlatoonMsg_m.h"
#include <veins/modules/application/visoesPlatoon/managerPlatoon.h>
#include <vector>
#include <veins/modules/application/visoesPlatoon/mensagensRecebidasPlatoon.h>
#include <veins/modules/application/visoesPlatoon/Lider.h>
#include <iostream>
#include <mutex>

using namespace omnetpp;

namespace veins {

/**
 * TODO - Generated class
 */
class VEINS_API VisoesPlatoon : public DemoBaseApplLayer
{
  public:
    enum DemoApplMessageKinds {
            SEND_BEACON_EVT,
            SEND_WSA_EVT,
            SEND_BEACON_PLATOON_EVT,
            MANUTENCAO_VISAO
    };

    cMessage *eventoEnviaBeaconPelotao;
    cMessage *eventoManutencaoPelotao;
    simtime_t periodoDeEnvioBeaconPelotao;
    simtime_t tempoInicioEnvioBeaconPelotao;
    simtime_t tempoDisseminacaoProtocolo;
    simtime_t atraso = 0;
    std:: mutex mtx;

    double tempoLimite;//mudar este nome
    double tempoSimulacao;
    double periodoRealSimulacao;
    int countBeaconRecebidoNoCanal = 0 ;
    simtime_t tempoEtapaManutencao;

    std::vector<int> liders;
    std::vector<mensagensRecebidasPlatoon*> listaMsgRecebidas;
    std::vector<mensagensRecebidasPlatoon*> listaMsgTemporarias;

    std::vector<mensagensRecebidasPlatoon*> listaVizinhosDetectados;
    std::vector<Visao*> listavisaoConhecidasDoCarro;
    std::vector<Visao*> listavisaoTemporaria;
    std::vector<int> listaMsgFalhas;

    int totalCarrosSimulacao = 0;
    int constPosLider = 0;
    int constPosVersao= 1;
    int constPosMembros = 2;

    int tamByteBeacon=0;
    bool utilizaAtrasoRandomico = false;
    bool utilizaAtrasoPorIdCarro = false;
    int percentualFalhas=0;
    int numBeaconFalhosnosCanais=0;
    int numBeaconsASeremTransmitidos=0;
    int countUltimaMsgManutencao = 0;
    std::stringstream dadosAEnviar;

    void initialize(int stage) override;
  protected:
    int idCar;
    bool eHLider = false;

    char* nameArquivoBeacon;
    char* nameArquivoVisao;
    Lider *dadoslider;
    virtual void initialize();
    virtual void  finish();
    void handleSelfMsg(cMessage* msg) override;
    void onBSM(DemoSafetyMessage* bsm) override;
    void onWSM(BaseFrame1609_4* wsm) override;
    void onWSA(DemoServiceAdvertisment* wsa) override;
    void enviaBeaconPelotao();
    void recebeBeaconPelotao(VisoesPlatoonMsg *pmsgBeacon);
    bool existeMsgNaListaDeMsgRecebidas(int idLider);
    managerPlatoon* getManagerPlatoons();
    int incrementIdCarPlatoons();
    void etapaManutencao(cMessage* msg);
    void desencapsulaVisoesConhecidasDoBeacon(VisoesPlatoonMsg *pmsgBeacon,
            mensagensRecebidasPlatoon* msgRecebida);
    void initializeParameters();
    void gerenciaLiderPelotao();
    int pegaIndiceMsgLiderEmVisoesConhecidas(int pIdLider, int pVersao, int pMembros);
    void gerenciaVisoesConhecidas(mensagensRecebidasPlatoon* msg);
    void gerenciaVisoesConhecidasDaMsg(mensagensRecebidasPlatoon* msg);
    int pegaIndiceMsgNaListaDeMsgRecebidas(int idLider);
    void encapsulaVisoesBeaconPelotao(VisoesPlatoonMsg* novaVisao);
    int pegaIndiceMsgLiderEmVisoesConhecidasDoBeacon(mensagensRecebidasPlatoon* msg, int pLider);
    char* geraArquivoDosBeacons(
       char * pNameFileBeacon, std::vector<mensagensRecebidasPlatoon*> listaMsgVizinhos);
    char* getVizinhosDaMsg( std::vector<Visao*> pListaVisoesDaMsg);
    double getAtraso();
    void geraVetorDeFalhas();
    bool existeMsgNaListaDeFalhas(int pIdMSg);


};
}
#endif
