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
#include "veins/modules/application/traci/TraCIDemo11pMessage_m.h"
#include "VisoesPlatoon.h"
#include "VisoesPlatoonMsg_m.h"
#include <veins/modules/application/visoesPlatoon/managerPlatoon.h>
#include <iostream>
#include <stdlib.h>
#include <mutex>
using namespace veins;

Define_Module(veins::VisoesPlatoon);

void VisoesPlatoon::initialize()
{
    // TODO - Generated method body
}

void VisoesPlatoon::initialize(int stage)
{  simtime_t primeiroBeaconPelotao;
   simtime_t primeiraManutencaoVisao;
   //Quando liga a chave do carro
    DemoBaseApplLayer::initialize(stage);
    if (stage==0)
    {
       idCar = incrementIdCarPlatoons();
       std::cout<<"countCar="<<idCar;
       initializeParameters();

       eventoEnviaBeaconPelotao = new cMessage("beacon Platoon evt",
          SEND_BEACON_PLATOON_EVT);
       eventoManutencaoPelotao = new cMessage("synchronize Platoon evt", MANUTENCAO_VISAO);
    }
    //Quando começa a disparar beacons
    if(stage ==1)
    {
        tempoInicioEnvioBeaconPelotao = tempoDisseminacaoProtocolo +
          periodoDeEnvioBeaconPelotao + getAtraso();
        primeiroBeaconPelotao = tempoInicioEnvioBeaconPelotao;
        primeiraManutencaoVisao = tempoDisseminacaoProtocolo + tempoEtapaManutencao;
        if (idCar > 20)
        {
           std::cout<<"\n TimeAtual = "<<simTime().dbl();
        }

        scheduleAt(primeiroBeaconPelotao, eventoEnviaBeaconPelotao);
        scheduleAt(primeiraManutencaoVisao, eventoManutencaoPelotao);

    }

}

void VisoesPlatoon::gerenciaLiderPelotao()
{
    //Colocar um case para cada pelotão que for rodar
    // o numero do case representa o numero do líder
    //

    switch(idCar)
    {      //lider identificado como idCar=2
         case 1:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 1;
             eHLider = true;
             break;
        /*  case 2:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 2;
             eHLider = true;
             break;
          case 3:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 3;
             eHLider = true;
             break;
          case 4:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 4;
             eHLider = true;
          */   break;
          case 5:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 5;
             eHLider = true;
             break;
         /* case 6:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 6;
             eHLider = true;
             break;
          case 7:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 7;
             eHLider = true;
             break;
          case 8:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 8;
             eHLider = true;
            break;
          case 9:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 9;
             eHLider = true;
            break;
          case 10:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 10;
             eHLider = true;
            break;
          case 11:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros =11;
             eHLider = true;
            break;
          case 12:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros =12;
             eHLider = true;
            break;
          case 13:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 13;
             eHLider = true;
            break;
          case 14:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 14;
             eHLider = true;
            break;*/
          case 15:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 15;
             eHLider = true;
            break;
       /*   case 16:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 0;
             eHLider = true;
            break;
          case 17:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 0;
             eHLider = true;
            break;
          case 18:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 0;
             eHLider = true;
            break;
          case 19:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 0;
             eHLider = true;
            break;
          case 20:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 0;
             eHLider = true;
            break;
          case 21:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 0;
             eHLider = true;
            break;
          case 22:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 0;
             eHLider = true;
            break;
          case 23:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 0;
             eHLider = true;
            break;
          case 24:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 0;
             eHLider = true;
            break;
          case 25:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 0;
             eHLider = true;
            break;
          case 26:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 0;
             eHLider = true;
            break;
          case 27:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 0;
             eHLider = true;
            break;
          case 28:
             dadoslider = new Lider();
             dadoslider->idLider=idCar;
             dadoslider->membros = 0;
             eHLider = true;
            break;
          case 29:
            dadoslider = new Lider();
            dadoslider->idLider=idCar;
            dadoslider->membros = 0;
            eHLider = true;
           break;
         case 30:
            dadoslider = new Lider();
            dadoslider->idLider=idCar;
            dadoslider->membros = 0;
            eHLider = true;
          break;  */

    }
}

void VisoesPlatoon::initializeParameters()
{
    //A verificação e os dados dos líderes devem ser inseridos neste método
    gerenciaLiderPelotao();
    //tempo limite a ser inserido no cronometro
    this->tempoLimite = 1.0;
    this->tempoEtapaManutencao = tempoLimite;
    this->tempoDisseminacaoProtocolo = 250;
    /*a variável beaconinterval é configurado dentro do arquivo VisoesPlatoon.ini
     *que é excutado para rodar o pelotão
     *para não conflitar no tempo. simulação de dois canais
     * Se a aplicação for enviar apenas os beacons do pelotão, configure o ini com
     * sendBeacon = false*/

    this->periodoDeEnvioBeaconPelotao = beaconInterval; //+ (beaconInterval/2) O intervalo vem do arquivo Pelotoes.ini

    this->nameArquivoBeacon = "dados_";
    std::stringstream dadosArquivo;

    //Caso haja necessidade de setar um tamanho fixo do beacon
    this->tamByteBeacon = 512;
    //Se nenhum atraso for configurado, a APP enviará beacon ao mesmo tempo
    //em todos os carros
    this->utilizaAtrasoRandomico = true;
    this->utilizaAtrasoPorIdCarro = false;
    //Inserir a mesma quantidade configurada no arquivo do cenário do SUmo
    totalCarrosSimulacao = 30;//20;

    //*********Configuração de Falhas***********
    this->tempoSimulacao=100; //Pegar do Arquivo *.ini
    this->percentualFalhas = 0;  //10%, 20%, 30%???
    this->periodoRealSimulacao = (this->tempoSimulacao- this->tempoDisseminacaoProtocolo.dbl());
    this->numBeaconsASeremTransmitidos = ((this->periodoRealSimulacao / this->periodoDeEnvioBeaconPelotao.dbl())
            *(totalCarrosSimulacao -1));
    this->numBeaconFalhosnosCanais= (this->numBeaconsASeremTransmitidos*this->percentualFalhas)/100;
    geraVetorDeFalhas();


}
managerPlatoon* VisoesPlatoon::getManagerPlatoons()
{
    static managerPlatoon *moduleManagerPlatoon;
    if (moduleManagerPlatoon ==NULL)
    {
        moduleManagerPlatoon = new managerPlatoon();
    }
    return moduleManagerPlatoon;
}

int VisoesPlatoon::incrementIdCarPlatoons()
{
    getManagerPlatoons()->incrementCountCar();
    return getManagerPlatoons()->getCountCar();
}

double VisoesPlatoon::getAtraso()
{
     //2  => 0.00022222 ; 3 => 0.0003333atraso = idCar*0.0001111;  //2  => 0.00022222 ; 3 => 0.0003333atraso = idCar*0.0001111;  //2  => 0.00022222 ; 3 => 0.0003333
    srand(idCar);
    if (utilizaAtrasoRandomico)
    {
        atraso = rand() % 99; //pega um intervalo entre 0 e 99
        atraso = atraso / 1000; //para dar milesimos de segundos
        return  atraso.dbl() + idCar*0.0001111;
    }
    else if (utilizaAtrasoPorIdCarro)
    {
      atraso = idCar*0.00111;  //idCar=2  => 0.00022222 ; 3 => 0.0003333
      return  atraso.dbl();
    }
    else
      return 0;
}


void VisoesPlatoon::enviaBeaconPelotao()
{

   simtime_t tempoEnvio = simTime() + getAtraso();
   std::cout<<"Tempo de Envio = "<<tempoEnvio.dbl()<<" tempo atual do Sim.="<<simTime().dbl();
   if (eHLider)
   {
     VisoesPlatoonMsg* novaVisao = new VisoesPlatoonMsg("Msg Platoon");


     //dadoslider->versao++;
     novaVisao->setIdLider(dadoslider->idLider);
     novaVisao->setTempoEnvio(tempoEnvio.dbl());
     novaVisao->setVisoesArraySize(3);
    // novaVisao->setTexto(this->dadosAEnviar.str().c_str());


     //contrução da visão do pelotão
     //configura o idLider do Platoon
     novaVisao->setVisoes(constPosLider, dadoslider->idLider);
     //configura a versão do Platoon
     novaVisao->setVisoes(constPosVersao, dadoslider->versao);
     //configura o nº de veículos do Platoon
     novaVisao->setVisoes(constPosMembros, dadoslider->membros);
    //insere os dados do veículo e da localização

     //Inclui as visões nas mensagens
     encapsulaVisoesBeaconPelotao(novaVisao);


     //Inclui os dados do carro e da rodovia

     populateWSM(novaVisao);
     //cleber pediu para eu remover isso aqui
     novaVisao->addByteLength(this->tamByteBeacon);

     std::cout<<"\n tamBeacon a enviar"<<novaVisao->getByteLength();

     atraso = getAtraso();
     //Envia primeiro Beacon com um delay que é calculado com o Id de cada carro
     if (atraso.dbl() >0)
       sendDelayedDown(novaVisao->dup(), atraso);
     else
       sendDown(novaVisao->dup());
   }
   else
   {
      VisoesPlatoonMsg* novoBeacon = new VisoesPlatoonMsg("Msg Platoon");
      novoBeacon->setIdLider(-1); //Não é líder

      populateWSM(novoBeacon);
      atraso = getAtraso();
      //Envia primeiro Beacon com um delay que é calculado com o Id de cada carro
      if (atraso.dbl() >0)
         sendDelayedDown(novoBeacon->dup(), atraso);
      else
             sendDown(novoBeacon->dup());


   }

}

bool VisoesPlatoon:: existeMsgNaListaDeFalhas(int pIdMSg)
{   bool result = false;

    for(int i=0;i<listaMsgFalhas.size(); i++)
    {
       if (listaMsgFalhas[i] == pIdMSg)
       {
            result = true;
            break;
        }

    }


    return result;
}


void VisoesPlatoon::geraVetorDeFalhas()
{ bool numMsgFalhas;
  bool continueRang = true;
  int numero_randomico = 0;
  bool isValidRange = false;

  //Limpa o buffer para gerar números aleatórios diferentes
  std::cout<<" VetorFalhas = ";
  srand((unsigned) time(NULL));
  //srand(countMSGsTotalToSend);

    for(int countFalha=0; countFalha<this->numBeaconFalhosnosCanais; countFalha++)
    {
        continueRang = true;
        while(continueRang)
        {   continueRang = true;
            numero_randomico = 1+(rand() % (this->numBeaconsASeremTransmitidos));
            isValidRange =(numero_randomico > 0 &&
                    numero_randomico <= this->numBeaconsASeremTransmitidos);

            if (isValidRange)
            {  if (!existeMsgNaListaDeFalhas(numero_randomico))
               {
                listaMsgFalhas.push_back(numero_randomico);
                continueRang = false;
                break;
               }

            }
        }


        std::cout<< numero_randomico<<",";

    }
    //Gera um vetor com os códigos das falhas
    //loadListRandomOfFailure();

    std::cout<<"\n";
}


void VisoesPlatoon::encapsulaVisoesBeaconPelotao(VisoesPlatoonMsg* novaVisao)
{
  novaVisao->setQtdVisoesConhecidas(listavisaoConhecidasDoCarro.size());
  for(int i=1; i<=listavisaoConhecidasDoCarro.size(); i++)
  {
      switch (i)
      {
          case 1:
              novaVisao->setVisoesConhecidas1ArraySize(3);
              novaVisao->setVisoesConhecidas1(constPosLider, listavisaoConhecidasDoCarro[0]->idLider);
              novaVisao->setVisoesConhecidas1(constPosMembros,listavisaoConhecidasDoCarro[0]->membros);
              novaVisao->setVisoesConhecidas1(constPosVersao,listavisaoConhecidasDoCarro[0]->versao);
              break;
          case 2:
              novaVisao->setVisoesConhecidas2ArraySize(3);
              novaVisao->setVisoesConhecidas2(constPosLider, listavisaoConhecidasDoCarro[1]->idLider);
              novaVisao->setVisoesConhecidas2(constPosMembros,listavisaoConhecidasDoCarro[1]->membros);
              novaVisao->setVisoesConhecidas2(constPosVersao,listavisaoConhecidasDoCarro[1]->versao);
              break;
          case 3:
              novaVisao->setVisoesConhecidas3ArraySize(3);
              novaVisao->setVisoesConhecidas3(constPosLider, listavisaoConhecidasDoCarro[2]->idLider);
              novaVisao->setVisoesConhecidas3(constPosMembros,listavisaoConhecidasDoCarro[2]->membros);
              novaVisao->setVisoesConhecidas3(constPosVersao,listavisaoConhecidasDoCarro[2]->versao);
              break;
          case 4:
              novaVisao->setVisoesConhecidas4ArraySize(3);
              novaVisao->setVisoesConhecidas4(constPosLider, listavisaoConhecidasDoCarro[3]->idLider);
              novaVisao->setVisoesConhecidas4(constPosMembros,listavisaoConhecidasDoCarro[3]->membros);
              novaVisao->setVisoesConhecidas4(constPosVersao,listavisaoConhecidasDoCarro[3]->versao);
              break;
          case 5:
              novaVisao->setVisoesConhecidas5ArraySize(3);
              novaVisao->setVisoesConhecidas5(constPosLider, listavisaoConhecidasDoCarro[4]->idLider);
              novaVisao->setVisoesConhecidas5(constPosMembros,listavisaoConhecidasDoCarro[4]->membros);
              novaVisao->setVisoesConhecidas5(constPosVersao,listavisaoConhecidasDoCarro[4]->versao);
              break;
          case 6:
              novaVisao->setVisoesConhecidas6ArraySize(3);
              novaVisao->setVisoesConhecidas6(constPosLider, listavisaoConhecidasDoCarro[5]->idLider);
              novaVisao->setVisoesConhecidas6(constPosMembros,listavisaoConhecidasDoCarro[5]->membros);
              novaVisao->setVisoesConhecidas6(constPosVersao,listavisaoConhecidasDoCarro[5]->versao);
              break;
          case 7:
              novaVisao->setVisoesConhecidas7ArraySize(3);
              novaVisao->setVisoesConhecidas7(constPosLider, listavisaoConhecidasDoCarro[6]->idLider);
              novaVisao->setVisoesConhecidas7(constPosMembros,listavisaoConhecidasDoCarro[6]->membros);
              novaVisao->setVisoesConhecidas7(constPosVersao,listavisaoConhecidasDoCarro[6]->versao);
              break;
          case 8:
              novaVisao->setVisoesConhecidas8ArraySize(3);
              novaVisao->setVisoesConhecidas8(constPosLider, listavisaoConhecidasDoCarro[7]->idLider);
              novaVisao->setVisoesConhecidas8(constPosMembros,listavisaoConhecidasDoCarro[7]->membros);
              novaVisao->setVisoesConhecidas8(constPosVersao,listavisaoConhecidasDoCarro[7]->versao);
              break;
          case 9:
              novaVisao->setVisoesConhecidas9ArraySize(3);
              novaVisao->setVisoesConhecidas9(constPosLider, listavisaoConhecidasDoCarro[8]->idLider);
              novaVisao->setVisoesConhecidas9(constPosMembros,listavisaoConhecidasDoCarro[8]->membros);
              novaVisao->setVisoesConhecidas9(constPosVersao,listavisaoConhecidasDoCarro[8]->versao);
              break;
          case 10:
              novaVisao->setVisoesConhecidas10ArraySize(3);
              novaVisao->setVisoesConhecidas10(constPosLider, listavisaoConhecidasDoCarro[9]->idLider);
              novaVisao->setVisoesConhecidas10(constPosMembros,listavisaoConhecidasDoCarro[9]->membros);
              novaVisao->setVisoesConhecidas10(constPosVersao,listavisaoConhecidasDoCarro[9]->versao);
              break;
          case 11:
              novaVisao->setVisoesConhecidas11ArraySize(3);
              novaVisao->setVisoesConhecidas11(constPosLider, listavisaoConhecidasDoCarro[10]->idLider);
              novaVisao->setVisoesConhecidas11(constPosMembros,listavisaoConhecidasDoCarro[10]->membros);
              novaVisao->setVisoesConhecidas11(constPosVersao,listavisaoConhecidasDoCarro[10]->versao);
              break;
          case 12:
              novaVisao->setVisoesConhecidas12ArraySize(3);
              novaVisao->setVisoesConhecidas12(constPosLider, listavisaoConhecidasDoCarro[11]->idLider);
              novaVisao->setVisoesConhecidas12(constPosMembros,listavisaoConhecidasDoCarro[11]->membros);
              novaVisao->setVisoesConhecidas12(constPosVersao,listavisaoConhecidasDoCarro[11]->versao);
              break;
          case 13:
              novaVisao->setVisoesConhecidas13ArraySize(3);
              novaVisao->setVisoesConhecidas13(constPosLider, listavisaoConhecidasDoCarro[12]->idLider);
              novaVisao->setVisoesConhecidas13(constPosMembros,listavisaoConhecidasDoCarro[12]->membros);
              novaVisao->setVisoesConhecidas13(constPosVersao,listavisaoConhecidasDoCarro[12]->versao);
              break;
          case 14:
              novaVisao->setVisoesConhecidas14ArraySize(3);
              novaVisao->setVisoesConhecidas14(constPosLider, listavisaoConhecidasDoCarro[13]->idLider);
              novaVisao->setVisoesConhecidas14(constPosMembros,listavisaoConhecidasDoCarro[13]->membros);
              novaVisao->setVisoesConhecidas14(constPosVersao,listavisaoConhecidasDoCarro[13]->versao);
              break;
          case 15:
              novaVisao->setVisoesConhecidas15ArraySize(3);
              novaVisao->setVisoesConhecidas15(constPosLider, listavisaoConhecidasDoCarro[14]->idLider);
              novaVisao->setVisoesConhecidas15(constPosMembros,listavisaoConhecidasDoCarro[14]->membros);
              novaVisao->setVisoesConhecidas15(constPosVersao,listavisaoConhecidasDoCarro[14]->versao);
              break;
          case 16:
              novaVisao->setVisoesConhecidas16ArraySize(3);
              novaVisao->setVisoesConhecidas16(constPosLider, listavisaoConhecidasDoCarro[15]->idLider);
              novaVisao->setVisoesConhecidas16(constPosMembros,listavisaoConhecidasDoCarro[15]->membros);
              novaVisao->setVisoesConhecidas16(constPosVersao,listavisaoConhecidasDoCarro[15]->versao);
              break;
          case 17:
              novaVisao->setVisoesConhecidas17ArraySize(3);
              novaVisao->setVisoesConhecidas17(constPosLider, listavisaoConhecidasDoCarro[16]->idLider);
              novaVisao->setVisoesConhecidas17(constPosMembros,listavisaoConhecidasDoCarro[16]->membros);
              novaVisao->setVisoesConhecidas17(constPosVersao,listavisaoConhecidasDoCarro[16]->versao);
              break;
          case 18:
              novaVisao->setVisoesConhecidas18ArraySize(3);
              novaVisao->setVisoesConhecidas18(constPosLider, listavisaoConhecidasDoCarro[17]->idLider);
              novaVisao->setVisoesConhecidas18(constPosMembros,listavisaoConhecidasDoCarro[17]->membros);
              novaVisao->setVisoesConhecidas18(constPosVersao,listavisaoConhecidasDoCarro[17]->versao);
              break;
          case 19:
              novaVisao->setVisoesConhecidas19ArraySize(3);
              novaVisao->setVisoesConhecidas19(constPosLider, listavisaoConhecidasDoCarro[18]->idLider);
              novaVisao->setVisoesConhecidas19(constPosMembros,listavisaoConhecidasDoCarro[18]->membros);
              novaVisao->setVisoesConhecidas19(constPosVersao,listavisaoConhecidasDoCarro[18]->versao);
              break;
          case 20:
              novaVisao->setVisoesConhecidas20ArraySize(3);
              novaVisao->setVisoesConhecidas20(constPosLider, listavisaoConhecidasDoCarro[19]->idLider);
              novaVisao->setVisoesConhecidas20(constPosMembros,listavisaoConhecidasDoCarro[19]->membros);
              novaVisao->setVisoesConhecidas20(constPosVersao,listavisaoConhecidasDoCarro[19]->versao);
              break;
          case 21:
              novaVisao->setVisoesConhecidas21ArraySize(3);
              novaVisao->setVisoesConhecidas21(constPosLider, listavisaoConhecidasDoCarro[20]->idLider);
              novaVisao->setVisoesConhecidas21(constPosMembros,listavisaoConhecidasDoCarro[20]->membros);
              novaVisao->setVisoesConhecidas21(constPosVersao,listavisaoConhecidasDoCarro[20]->versao);
              break;
          case 22:
              novaVisao->setVisoesConhecidas22ArraySize(3);
              novaVisao->setVisoesConhecidas22(constPosLider, listavisaoConhecidasDoCarro[21]->idLider);
              novaVisao->setVisoesConhecidas22(constPosMembros,listavisaoConhecidasDoCarro[21]->membros);
              novaVisao->setVisoesConhecidas22(constPosVersao,listavisaoConhecidasDoCarro[21]->versao);
              break;
          case 23:
              novaVisao->setVisoesConhecidas23ArraySize(3);
              novaVisao->setVisoesConhecidas23(constPosLider, listavisaoConhecidasDoCarro[22]->idLider);
              novaVisao->setVisoesConhecidas23(constPosMembros,listavisaoConhecidasDoCarro[22]->membros);
              novaVisao->setVisoesConhecidas23(constPosVersao,listavisaoConhecidasDoCarro[22]->versao);
              break;
          case 24:
              novaVisao->setVisoesConhecidas24ArraySize(3);
              novaVisao->setVisoesConhecidas24(constPosLider, listavisaoConhecidasDoCarro[23]->idLider);
              novaVisao->setVisoesConhecidas24(constPosMembros,listavisaoConhecidasDoCarro[23]->membros);
              novaVisao->setVisoesConhecidas24(constPosVersao,listavisaoConhecidasDoCarro[23]->versao);
              break;
          case 25:
              novaVisao->setVisoesConhecidas25ArraySize(3);
              novaVisao->setVisoesConhecidas25(constPosLider, listavisaoConhecidasDoCarro[24]->idLider);
              novaVisao->setVisoesConhecidas25(constPosMembros,listavisaoConhecidasDoCarro[24]->membros);
              novaVisao->setVisoesConhecidas25(constPosVersao,listavisaoConhecidasDoCarro[24]->versao);
              break;
          case 26:
              novaVisao->setVisoesConhecidas26ArraySize(3);
              novaVisao->setVisoesConhecidas26(constPosLider, listavisaoConhecidasDoCarro[25]->idLider);
              novaVisao->setVisoesConhecidas26(constPosMembros,listavisaoConhecidasDoCarro[25]->membros);
              novaVisao->setVisoesConhecidas26(constPosVersao,listavisaoConhecidasDoCarro[25]->versao);
              break;
          case 27:
              novaVisao->setVisoesConhecidas27ArraySize(3);
              novaVisao->setVisoesConhecidas27(constPosLider, listavisaoConhecidasDoCarro[26]->idLider);
              novaVisao->setVisoesConhecidas27(constPosMembros,listavisaoConhecidasDoCarro[26]->membros);
              novaVisao->setVisoesConhecidas27(constPosVersao,listavisaoConhecidasDoCarro[26]->versao);
              break;
          case 28:
              novaVisao->setVisoesConhecidas28ArraySize(3);
              novaVisao->setVisoesConhecidas28(constPosLider, listavisaoConhecidasDoCarro[27]->idLider);
              novaVisao->setVisoesConhecidas28(constPosMembros,listavisaoConhecidasDoCarro[27]->membros);
              novaVisao->setVisoesConhecidas28(constPosVersao,listavisaoConhecidasDoCarro[27]->versao);
              break;
          case 29:
              novaVisao->setVisoesConhecidas29ArraySize(3);
              novaVisao->setVisoesConhecidas29(constPosLider, listavisaoConhecidasDoCarro[28]->idLider);
              novaVisao->setVisoesConhecidas29(constPosMembros,listavisaoConhecidasDoCarro[28]->membros);
              novaVisao->setVisoesConhecidas29(constPosVersao,listavisaoConhecidasDoCarro[28]->versao);
              break;
          case 30:
              novaVisao->setVisoesConhecidas30ArraySize(3);
              novaVisao->setVisoesConhecidas30(constPosLider, listavisaoConhecidasDoCarro[29]->idLider);
              novaVisao->setVisoesConhecidas30(constPosMembros,listavisaoConhecidasDoCarro[29]->membros);
              novaVisao->setVisoesConhecidas30(constPosVersao,listavisaoConhecidasDoCarro[29]->versao);
              break;

      }
  }
}

bool VisoesPlatoon::existeMsgNaListaDeMsgRecebidas(int idLider)
{  bool resultado= false;
   for(int i = 0; i< listaMsgRecebidas.size(); i++)
   {
       if (listaMsgRecebidas[i]->idLider == idLider)
       {
           resultado = true;
           return resultado;
       }
   }
   return resultado;
}

int VisoesPlatoon::pegaIndiceMsgNaListaDeMsgRecebidas(int idLider)
{  int resultado= -1;
   for(int i = 0; i< listaMsgRecebidas.size(); i++)
   {
       if (listaMsgRecebidas[i]->idLider == idLider)
       {
           resultado = i;
           return resultado;
       }
   }
   return resultado;
}

void VisoesPlatoon::desencapsulaVisoesConhecidasDoBeacon(
        VisoesPlatoonMsg *pmsgBeacon,
        mensagensRecebidasPlatoon* pMsgRecebida)
{
    int posLider = 0;
    int posVersao = 1;
    int posMembros = 2;
    pMsgRecebida->qtdVisoesConhecidas = pmsgBeacon->getQtdVisoesConhecidas();
    if (pmsgBeacon->getQtdVisoesConhecidas() > 0)
    {
       for (int i=1; i<= pmsgBeacon->getQtdVisoesConhecidas(); i++)
       {
         Visao * visao_i = new Visao();
         pMsgRecebida->listaVisoesConhecidas.push_back(visao_i);
         switch(i)
         {
           case 1:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas1(posLider);
             visao_i->membros = pmsgBeacon->getVisoesConhecidas1(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas1(posVersao);
             break;
           case 2:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas2(posLider);
             visao_i->membros = pmsgBeacon->getVisoesConhecidas2(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas2(posVersao);
             break;
           case 3:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas3(posLider);
             visao_i->membros = pmsgBeacon->getVisoesConhecidas3(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas3(posVersao);
             break;
           case 4:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas4(posLider);
             visao_i->membros = pmsgBeacon->getVisoesConhecidas4(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas4(posVersao);
             break;
           case 5:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas5(posLider);
             visao_i->membros= pmsgBeacon->getVisoesConhecidas5(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas5(posVersao);
             break;
           case 6:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas6(posLider);
             visao_i->membros = pmsgBeacon->getVisoesConhecidas6(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas6(posVersao);
             break;
           case 7:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas7(posLider);
             visao_i->membros = pmsgBeacon->getVisoesConhecidas7(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas7(posVersao);
             break;
           case 8:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas8(posLider);
             visao_i->membros = pmsgBeacon->getVisoesConhecidas8(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas8(posVersao);
             break;
           case 9:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas9(posLider);
             visao_i->membros = pmsgBeacon->getVisoesConhecidas9(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas9(posVersao);
             break;
           case 10:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas10(posLider);
             visao_i->membros = pmsgBeacon->getVisoesConhecidas10(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas10(posVersao);
             break;
           case 11:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas11(posLider);
             visao_i->membros= pmsgBeacon->getVisoesConhecidas11(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas11(posVersao);
             break;
           case 12:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas12(posLider);
             visao_i->membros= pmsgBeacon->getVisoesConhecidas12(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas12(posVersao);
             break;
           case 13:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas13(posLider);
             visao_i->membros= pmsgBeacon->getVisoesConhecidas13(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas13(posVersao);
             break;
           case 14:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas14(posLider);
             visao_i->membros= pmsgBeacon->getVisoesConhecidas14(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas14(posVersao);
             break;
           case 15:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas15(posLider);
             visao_i->membros= pmsgBeacon->getVisoesConhecidas15(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas15(posVersao);
             break;
           case 16:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas16(posLider);
             visao_i->membros= pmsgBeacon->getVisoesConhecidas16(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas16(posVersao);
             break;
           case 17:
             visao_i->idLider = pmsgBeacon->getVisoesConhecidas17(posLider);
             visao_i->membros= pmsgBeacon->getVisoesConhecidas17(posMembros);
             visao_i->versao = pmsgBeacon->getVisoesConhecidas17(posVersao);
             break;

           case 18:
               visao_i->idLider = pmsgBeacon->getVisoesConhecidas18(posLider);
               visao_i->membros= pmsgBeacon->getVisoesConhecidas18(posMembros);
               visao_i->versao = pmsgBeacon->getVisoesConhecidas18(posVersao);
               break;
           case 19:
               visao_i->idLider = pmsgBeacon->getVisoesConhecidas19(posLider);
               visao_i->membros= pmsgBeacon->getVisoesConhecidas19(posMembros);
               visao_i->versao = pmsgBeacon->getVisoesConhecidas19(posVersao);
               break;
           case 20:
               visao_i->idLider = pmsgBeacon->getVisoesConhecidas20(posLider);
               visao_i->membros= pmsgBeacon->getVisoesConhecidas20(posMembros);
               visao_i->versao = pmsgBeacon->getVisoesConhecidas20(posVersao);
               break;
           case 21:
               visao_i->idLider = pmsgBeacon->getVisoesConhecidas21(posLider);
               visao_i->membros= pmsgBeacon->getVisoesConhecidas21(posMembros);
               visao_i->versao = pmsgBeacon->getVisoesConhecidas21(posVersao);
               break;
           case 22:
               visao_i->idLider = pmsgBeacon->getVisoesConhecidas22(posLider);
               visao_i->membros= pmsgBeacon->getVisoesConhecidas22(posMembros);
               visao_i->versao = pmsgBeacon->getVisoesConhecidas22(posVersao);
               break;
           case 23:
               visao_i->idLider = pmsgBeacon->getVisoesConhecidas23(posLider);
               visao_i->membros= pmsgBeacon->getVisoesConhecidas23(posMembros);
               visao_i->versao = pmsgBeacon->getVisoesConhecidas23(posVersao);
               break;
           case 24:
               visao_i->idLider = pmsgBeacon->getVisoesConhecidas24(posLider);
               visao_i->membros= pmsgBeacon->getVisoesConhecidas24(posMembros);
               visao_i->versao = pmsgBeacon->getVisoesConhecidas24(posVersao);
             break;
          case 25:
               visao_i->idLider = pmsgBeacon->getVisoesConhecidas25(posLider);
               visao_i->membros= pmsgBeacon->getVisoesConhecidas25(posMembros);
               visao_i->versao = pmsgBeacon->getVisoesConhecidas25(posVersao);
             break;
          case 26:
               visao_i->idLider = pmsgBeacon->getVisoesConhecidas26(posLider);
               visao_i->membros= pmsgBeacon->getVisoesConhecidas26(posMembros);
               visao_i->versao = pmsgBeacon->getVisoesConhecidas26(posVersao);
             break;
          case 27:
               visao_i->idLider = pmsgBeacon->getVisoesConhecidas27(posLider);
               visao_i->membros= pmsgBeacon->getVisoesConhecidas27(posMembros);
               visao_i->versao = pmsgBeacon->getVisoesConhecidas27(posVersao);
             break;
          case 28:
               visao_i->idLider = pmsgBeacon->getVisoesConhecidas28(posLider);
               visao_i->membros= pmsgBeacon->getVisoesConhecidas28(posMembros);
               visao_i->versao = pmsgBeacon->getVisoesConhecidas28(posVersao);
             break;
          case 29:
               visao_i->idLider = pmsgBeacon->getVisoesConhecidas29(posLider);
               visao_i->membros= pmsgBeacon->getVisoesConhecidas29(posMembros);
               visao_i->versao = pmsgBeacon->getVisoesConhecidas29(posVersao);
             break;
          case 30:
               visao_i->idLider = pmsgBeacon->getVisoesConhecidas30(posLider);
               visao_i->membros= pmsgBeacon->getVisoesConhecidas30(posMembros);
               visao_i->versao = pmsgBeacon->getVisoesConhecidas30(posVersao);
             break;
        }
      }
    }

}

void VisoesPlatoon::recebeBeaconPelotao(VisoesPlatoonMsg *pmsgBeacon)
{   int posVersao = 1;
    int posMembros = 2;

    countBeaconRecebidoNoCanal++;
    mensagensRecebidasPlatoon* msgRecebida = new mensagensRecebidasPlatoon();
    Visao* novaVisao = new Visao();
    //verificar se a msg já existe. Se existir, deve-se atualizar a msg ara manter a última versão
    if (eHLider  && msgRecebida->idLider >-1 && !existeMsgNaListaDeFalhas(countBeaconRecebidoNoCanal))
    {  //Somente um lider recebe msg de outro lider (idLider>0)

        msgRecebida->idLider = pmsgBeacon->getIdLider();
        msgRecebida->idPlatoon = pmsgBeacon->getIdPlatoon();
        msgRecebida->tempoEnvio = pmsgBeacon->getTempoEnvio();
        msgRecebida->visao = new Visao();
        msgRecebida->visao->idLider = pmsgBeacon->getIdLider();
        msgRecebida->visao->versao = pmsgBeacon->getVisoes(posVersao);
        msgRecebida->visao->membros = pmsgBeacon->getVisoes(posMembros);
        msgRecebida->tempRecebimento = simTime().dbl();
        msgRecebida->tamMsg = pmsgBeacon->getByteLength();//itLength();
        std::cout<<"\nmsgRecebida Pacote="<<pmsgBeacon->getByteLength();
        std::cout<<"\n*****tam = "<<pmsgBeacon->getByteLength();
        //linha 27 - mensagensRecebidas <- mensagensRecebidas U {receberMensagem()}
        listaMsgRecebidas.push_back(msgRecebida);
        desencapsulaVisoesConhecidasDoBeacon(pmsgBeacon, msgRecebida);
        gerenciaVisoesConhecidasDaMsg(msgRecebida);

    }



}

int VisoesPlatoon::pegaIndiceMsgLiderEmVisoesConhecidas(int pIdLider, int pVersao, int pMembros)
{  int result = -1;
   for(int i=0; i< listavisaoConhecidasDoCarro.size(); i++)
   {
      if (listavisaoConhecidasDoCarro[i]->idLider ==pIdLider
              && listavisaoConhecidasDoCarro[i]->versao == pVersao
              && listavisaoConhecidasDoCarro[i]->membros == pMembros)
      {
          result = i;
          return result;
      }
   }
   return result;
}



int VisoesPlatoon::pegaIndiceMsgLiderEmVisoesConhecidasDoBeacon(mensagensRecebidasPlatoon* msg, int pLider)
{  int result = -1;
   for(int i=0; i< msg->listaVisoesConhecidas.size(); i++)
   {
      //Se nas viões conhecidas existe um ID igual ao ID deste lider, deve-se retornar o código da visão
      if (msg->listaVisoesConhecidas[i]->idLider ==pLider)
      {
          result = i;
          return result;
      }
   }
   return result;
}

void VisoesPlatoon::gerenciaVisoesConhecidasDaMsg(mensagensRecebidasPlatoon* msg)
{  //listaMsgTemporarias
    int indiceMsgVisoesConhecidas = -1;
    int indiceMsgVisoesDoCarro= -1;
    int liderVisao;
    bool existMgVisaoConhecida = false;
    bool existMgVisaoDoCarro = false;

    //Trocar lista de Visoes para VisoesConhecidas
    //for é igual "para cada"
       // linha 15 - se m.idLider != idLider
       if (msg->idLider != idCar)
           //colocar a visao mais atualizada
       {   liderVisao =  msg->idLider;
           for(int v=0; v< msg->listaVisoesConhecidas.size();v++)
           {
               indiceMsgVisoesConhecidas = pegaIndiceMsgLiderEmVisoesConhecidas(msg->listaVisoesConhecidas[v]->idLider,
                 msg->listaVisoesConhecidas[v]->versao,
                 msg->listaVisoesConhecidas[v]->membros);
               //Se o indice não existir na lista é porque a visão não está na lista
               existMgVisaoConhecida = indiceMsgVisoesConhecidas >= 0;

               if (!existMgVisaoConhecida)
                 // linha 16 - visoesConhecidas <- visoesConhecidas U {m.visao}
                 listavisaoConhecidasDoCarro.push_back(msg->listaVisoesConhecidas[v]);
            }

           indiceMsgVisoesDoCarro = pegaIndiceMsgLiderEmVisoesConhecidas(msg->idLider,
             msg->visao->versao,
             msg->visao->membros);
           existMgVisaoDoCarro = indiceMsgVisoesDoCarro >=0;
           if(!existMgVisaoDoCarro)
           {
             msg->visao->idLider = msg->idLider;
             listavisaoConhecidasDoCarro.push_back(msg->visao);
           }
       }

    //ApagaMsgRecebidas
}


void VisoesPlatoon::gerenciaVisoesConhecidas(mensagensRecebidasPlatoon* msg)
{  //listaMsgTemporarias
    int qtdElementos = listaMsgRecebidas.size();
    int indiceMsgVisoesConhecidas = -1;
    int liderVisao;

    //Trocar lista de Visoes para VisoesConhecidas
    //linha 9 - para cada m em mensagensRecebidas - algumas dúvidas na construção das linhas subsequentes
    for (int i=0; i<listaMsgRecebidas.size(); i++)
    {
       // se v.lider = m.lider
       if (listaMsgRecebidas[i]->idLider != idCar)
           //colocar a visao mais atualizada
       {   liderVisao =  listaMsgRecebidas[i]->idLider;
           for(int v=0; v<listaMsgRecebidas[i]->listaVisoesConhecidas.size();v++)
           {

               indiceMsgVisoesConhecidas =
                 pegaIndiceMsgLiderEmVisoesConhecidas(liderVisao,
                   listaMsgRecebidas[i]->listaVisoesConhecidas[v]->versao,
                   listaMsgRecebidas[i]->listaVisoesConhecidas[v]->membros);
               //Se o indice não existir na lista é porque a visão não está na lista
               if (indiceMsgVisoesConhecidas <0)
                 listavisaoConhecidasDoCarro.push_back(listaMsgRecebidas[i]->listaVisoesConhecidas[v]);
               else
               {
                   listavisaoConhecidasDoCarro[indiceMsgVisoesConhecidas]->membros =  listaMsgRecebidas[i]->listaVisoesConhecidas[v]->membros;
                   listavisaoConhecidasDoCarro[indiceMsgVisoesConhecidas]->versao =  listaMsgRecebidas[i]->listaVisoesConhecidas[v]->versao;

               }
           }
       }

    }

    //ApagaMsgRecebidas
}

void VisoesPlatoon::etapaManutencao(cMessage* msg)
{  //listaMsgTemporarias
    int qtdElementos = listaMsgRecebidas.size();
    int indiceVisaoConhecidadoDesteCarro = -1;
    bool visaoDetectadaDesteLider= false;

    listaMsgTemporarias.clear();  ///lista de msg recebidas em um período
    listaMsgTemporarias = listaMsgRecebidas;
    std::cout<<"ListaMsgRecebidas="<< listaMsgRecebidas.size();
    std::cout<<"ListaTemporaria="<<listaMsgTemporarias.size();
    mtx.lock();
    //linha 31 - para cada m em mensagensTemporarias
    for (int i=0; i<listaMsgTemporarias.size(); i++)
    {
       //linha 32 - não foi necesário pq o método OnBSM já faz o teste
       //linha 34 - se v = visao ^ m.cronometro >= tempAux - tempoLimite
       //simTime().dbl() =relógio do simulador
       if (listaMsgTemporarias[i]->tempoEnvio >= simTime().dbl() - tempoLimite
               && listaMsgTemporarias[i]->idLider != idCar)
       {
           listaMsgTemporarias[i]->tempoDetecaoComoVizinho = simTime().dbl();

           //linha 33 - para cada v em m.visoesConhecidas
           for(int v=0; v<listaMsgTemporarias[i]->listaVisoesConhecidas.size();v++)
           {
               indiceVisaoConhecidadoDesteCarro =pegaIndiceMsgLiderEmVisoesConhecidasDoBeacon(listaMsgTemporarias[i], idCar);
               visaoDetectadaDesteLider= indiceVisaoConhecidadoDesteCarro >=0;

               //linha 34
               if (visaoDetectadaDesteLider && listaMsgTemporarias[i]->manutencaoEfetuada == false)
               {

                 listaMsgTemporarias[i]->tempoDetecaoComoVizinho = simTime().dbl();
                 //linha 35 - visoestemporarias <- visoesTemporarias U {m.visao}

                 //push_back - > insere na lista
                 listavisaoTemporaria.push_back(listaMsgTemporarias[i]->listaVisoesConhecidas[v]);
                 listaMsgTemporarias[i]->manutencaoEfetuada = true;
                 listaVizinhosDetectados.push_back(listaMsgTemporarias[i]);

               }

           }
        }
    }


    //Armazena os vizinhos no arquivo
    geraArquivoDosBeacons(this->nameArquivoBeacon, listaVizinhosDetectados);

    //Limpa as listas preenchidas no ciclo da manutenção
    listaMsgTemporarias.clear();
    listaVizinhosDetectados.clear();

    //Remove as mensages já processadas como vizinhos
    mtx.unlock();
}

//manipula eventos do carro e dos beacons
void VisoesPlatoon::handleSelfMsg(cMessage* msg)
{  int versao = 0;
   int membros = 0;
   double timeSimulator = simTime().dbl();
   simtime_t proximaManutencaoVisao, proximaEnvioBeaconPelotao;
   //&& TraCIDemo11pMessage* wsm = dynamic_cast<TraCIDemo11pMessage*>(msg))
   if (msg->getKind() == MANUTENCAO_VISAO)
   {
       etapaManutencao(msg);
       //escalona  aproxima etapa de Manutenção
       proximaManutencaoVisao = simTime() + tempoEtapaManutencao + 0.000000099; //simTime() é o cronometro
       //O tempo 0.000000099 foi incluído para editar concorrencia desta thread/evento com o evento de recebimento
       scheduleAt(proximaManutencaoVisao, eventoManutencaoPelotao);
   }else
   //melhorar o método para pegar o líder
   if (timeSimulator >=tempoDisseminacaoProtocolo.dbl() && (eHLider) &&
        msg->getKind() == SEND_BEACON_PLATOON_EVT)
    {

       enviaBeaconPelotao();
       //escalona o proximo evento de envio
       proximaEnvioBeaconPelotao = simTime() + periodoDeEnvioBeaconPelotao;
       scheduleAt(proximaEnvioBeaconPelotao, eventoEnviaBeaconPelotao);

    }
    else
    {   //trata os envios comuns dos beacons
        DemoBaseApplLayer::handleSelfMsg(msg);
    }

}
void VisoesPlatoon::onWSA(DemoServiceAdvertisment* wsa)
{
    // if this RSU receives a WSA for service 42, it will tune to the chan
    if (wsa->getPsid() == 42) {
        mac->changeServiceChannel(static_cast<Channel>(wsa->getTargetChannel()));
    }
}

//Esse método é herdado da classe do Veans. É ativado sempre que chega um novo beacon

void VisoesPlatoon::onBSM(DemoSafetyMessage* bsm)
{   //Só vai receber mensagem de um líder de pelotão. Envia mensagem do tipo visoesPlatoonMsg
    //bsmReceive é a variável que guardará o beacon recebido
    if (VisoesPlatoonMsg* bsmReceive = dynamic_cast<VisoesPlatoonMsg*>(bsm))
        {
           recebeBeaconPelotao(bsmReceive);

        }

};

void VisoesPlatoon::onWSM(BaseFrame1609_4* frame)
{
    DemoBaseApplLayer::onWSM(frame);
}

char * VisoesPlatoon::geraArquivoDosBeacons(
   char * pNameFileBeacon, std::vector<mensagensRecebidasPlatoon*> listaMsgVizinhos)
{   char* resultado = "";
    char* textoVisoes="";

    std::stringstream nomeArquivo;
    std::string visoes;

     //verifica se o arquivo não existe
     if ( getManagerPlatoons()->cfPtrArquivoBeacons  ==NULL)
     {   nomeArquivo << pNameFileBeacon<< "_QtdCar"<< this->totalCarrosSimulacao
                     << "_Beacon"<<beaconInterval.dbl()<<"_limite"<<this->tempoEtapaManutencao;
         if ( (getManagerPlatoons()->cfPtrArquivoBeacons = fopen(nomeArquivo.str().c_str(), "w" ) ) == NULL )
        {
          std::cout<<"Arquivo não pode ser aberto!";
        }
         else{
           fprintf(getManagerPlatoons()->cfPtrArquivoBeacons,"\n%s", "TamBytes;QtdCarros;idLiderLocal;tempoLimite;idLiderVizinho;Cronometro;TempoRecebimento;LatenciaRecebimento,TempoDetecção;LatenciaDeteccao;Vizinhos");

         }
     }
     if (getManagerPlatoons()->cfPtrArquivoBeacons != NULL)
     {
         for(int i=0; i < listaMsgVizinhos.size(); i++ )
         {

             textoVisoes = getVizinhosDaMsg(listaMsgVizinhos[i]->listaVisoesConhecidas);
             //comando para escrever no arquivo
             fprintf(getManagerPlatoons()->cfPtrArquivoBeacons,"\n%d;%d;%d;%f;%d;%f;%f;%f;%f;%f;%s", //%d = inteiro, %f = float, %s = String
                     // dados da impressão separados por vírgula
                     listaMsgVizinhos[i]->tamMsg,
                     totalCarrosSimulacao,//1
                     idCar,   //2    id do carro Local
                     tempoEtapaManutencao.dbl(),  //3
                     listaMsgVizinhos[i]->idLider, //idLiderVizinho
                     listaMsgVizinhos[i]->tempoEnvio, //5    //Tempo de envio
                     listaMsgVizinhos[i]->tempRecebimento,//6
                     (listaMsgVizinhos[i]->tempRecebimento -listaMsgVizinhos[i]->tempoEnvio) , //7   latencia de recebimento
                     listaMsgVizinhos[i]->tempoDetecaoComoVizinho, //8
                     listaMsgVizinhos[i]->tempoDetecaoComoVizinho - listaMsgVizinhos[i]->tempoEnvio,
                     textoVisoes);

         }//fim do for



     }
     return resultado;

}

char* VisoesPlatoon::getVizinhosDaMsg( std::vector<Visao*> pListaVisoesDaMsg)
{
  char* resultado = "";
  std::string teste = "";
  std::stringstream ss;

  for (int i = 0; i< pListaVisoesDaMsg.size(); i++)    {
      ss<<pListaVisoesDaMsg[i]->idLider << ";";
  }
  teste =  ss.str();
  resultado = &teste[0];
  return resultado;
}

void VisoesPlatoon::finish()
{
    fclose(getManagerPlatoons()->cfPtrArquivoBeacons);
}


