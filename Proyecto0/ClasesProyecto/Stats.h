#pragma once
#include "Local.h"

class Stats
{
    Local* MiLocal;
public:
    Stats(Local* local)
    {
        MiLocal = local;
    }

    float getTiempoEsperaPromedioEnArea(Area* area);
    int getTiquetesSolicitadosEnServicio(int servicio);
    int getTiquetesEmitidosEnUsuario(int usuario);
};
