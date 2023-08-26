//fila dinamica = dynamic queue 
typedef int TipoItem;

struct No{
    TipoItem valor;
    No* proximo;
};

class filadinamica
{
private:
    No* primeiro; //front
    No* ultimo; //rear
public:
    filadinamica(); //construtor
    ~filadinamica(); //destrutor
    bool estavazio(); //isEmpty
    bool estacheio();  //isFull
    void inserir(TipoItem item);
    TipoItem remover(); //dequeue //pop
    void imprimir();
};


