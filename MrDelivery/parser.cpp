#include <nlohmann/json.hpp>
using json = nlohmann::json;
#include "parser.h"

Grafo *Parser::structCreator(QString file){
    std::string utf8_text = file.toUtf8().constData();
    json j = json::parse(utf8_text);
    Grafo *nuevo = new Grafo();

    for (int i = 0 ; i < j["vertices"] ; ++i){
        nuevo->agregarVertice(QString::fromStdString(j["vertices"][i]));
    }
    for (int i = 0 ; i < j["aristas"] ; ++i){
        json ar = json::parse(j["aristas"][i]);
        Pedido *pedido = new Pedido(QString::fromStdString(ar["origen"]),QString::fromStdString(ar["destino"]),ar["costo"],ar["km"],ar["minutos"]);
        nuevo->agregarArista(QString::fromStdString(ar["origen"]),QString::fromStdString(ar["destino"]),pedido);

    }
    return nuevo;
}
