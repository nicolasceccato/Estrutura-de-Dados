
typedef struct {
    float x, y;
} Ponto;

void inicializa_ponto(Ponto *p);

void imprime_ponto(Ponto p);

float get_x(Ponto p);

float get_y(Ponto p);

float calcula_distancia(Ponto p, Ponto q);
