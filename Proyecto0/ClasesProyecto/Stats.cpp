#include "Stats.h"

float Stats::getTiempoEsperaPromedioEnArea(Area* area)
{
    float TiempoTotal = 0;
    float TiquetesAtendidos = 0;
    
    for (area->Ventanillas->goToStart(); !area->Ventanillas->atEnd(); area->Ventanillas->next())
    {
        auto VActual = area->Ventanillas->getElement();
        TiquetesAtendidos += (float) VActual->Atendidos;
        TiempoTotal+= VActual->TiqueteActual->getTiempoEspera();
    }
    return TiempoTotal/TiquetesAtendidos;
}

int Stats::getTiquetesSolicitadosEnServicio(int servicio)
{
    MiLocal->Servicios->goToPos(servicio);
    auto SActual = MiLocal->Servicios->getElement();
    return SActual->Solicitados;
}

int Stats::getTiquetesEmitidosEnUsuario(int usuario)
{
    MiLocal->TiposUsuario->goToPos(usuario);
    auto TActual = MiLocal->TiposUsuario->getElement();
    return TActual->Emitidos;
}
