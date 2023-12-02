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

#ifndef SRC_VEINS_MODULES_APPLICATION_VISOESPLATOON_MENSAGENSRECEBIDASPLATOON_H_
#define SRC_VEINS_MODULES_APPLICATION_VISOESPLATOON_MENSAGENSRECEBIDASPLATOON_H_
#include <vector>
#include <veins/modules/application/visoesPlatoon/Visao.h>

class mensagensRecebidasPlatoon {
public:
    int idLider;
    int idPlatoon;
    double tempoEnvio;
    double tempRecebimento;
    double tempoDetecaoComoVizinho;
    int tamMsg;
    int qtdVisoesConhecidas;
    bool manutencaoEfetuada = false;
    Visao *visao;//idLider, versão,membros
    std::vector<Visao*> listaVisoesConhecidas;

    mensagensRecebidasPlatoon();
    virtual ~mensagensRecebidasPlatoon();
};

#endif /* SRC_VEINS_MODULES_APPLICATION_VISOESPLATOON_MENSAGENSRECEBIDASPLATOON_H_ */
