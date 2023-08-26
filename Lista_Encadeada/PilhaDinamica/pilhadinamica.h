//Pilha dinamica = Dynamic Stack
typedef int TipoItem;

struct No //node
{
    TipoItem valor;
    No* proximo;
};


class PilhaDinamica {
    private:
      No* NoTopo;
    public:
     PilhaDinamica(); //construtor
    ~PilhaDinamica();//destrutor
     bool estavazio();//isEmpty
     bool estacheio(); //isFull
     void inserir(TipoItem item);//push // enqueue
     TipoItem remover();//pop // dequeue
     void imprimir();
};