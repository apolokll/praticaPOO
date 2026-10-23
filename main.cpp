#include <iostream>
#include <string>

class Produto{

    private:
        std::string nome;
        int codigo;
        double preco;
        int quantidadeEstoque;

        static int totalProdutos;


    public:
        Produto(std::string nome, int codigo, double preco, int quantidadeEstoque) {
            this->nome = nome;
            this->codigo = codigo;
            this->preco = preco;
            this->quantidadeEstoque = quantidadeEstoque;

            totalProdutos++;
        }

        Produto() {
            this->nome = "";
            this->codigo = 0;
            this->preco = 0.0;
            this->quantidadeEstoque = 0;

            totalProdutos++;
        }

        ~Produto() {
            std::cout << "Produto " << nome << " destruído." << std::endl;
        }


        std::string getNome() const {
            return nome;
        }
        int getCodigo() const {
            return codigo;
        }
        double getPreco() const {
            return preco;
        }
        int getQuantidadeEstoque() const {
            return quantidadeEstoque;
        }


        void setNome(std::string nome) {
            this->nome = nome;
        }
        void setCodigo(int codigo) {
            this->codigo = codigo;
        }
        void setPreco(double preco) {
            if (preco < 0)
            {
                this->preco = (preco < 0) ? 0.0 : preco;
            } else {
                this->preco = preco;
            }
        }
        void setQuantidadeEstoque(int quantidadeEstoque) {
            if (quantidadeEstoque < 0)
            {
                this->quantidadeEstoque = 0;
            } else {
                this->quantidadeEstoque = quantidadeEstoque;
            }
            
        }


        void exibirInformacoes() const{
            std::cout << "Nome: " << nome << std::endl;
            std::cout << "Código: " << codigo << std::endl;
            std::cout << "Preço: " << preco << std::endl;
            std::cout << "Quantidade em estoque: " << quantidadeEstoque << std::endl;
        }

        bool temEstoque() const {
            if(quantidadeEstoque > 0){
                return true;
            } else {
                return false;
            }
        }

        bool vender(int quantidade) {
            if (quantidade > 0 && quantidade <= quantidadeEstoque) {
                quantidadeEstoque -= quantidade;
                return true;
            }
            std::cout << "Estoque insuficiente para vender " << quantidade << " unidades.\n";
            return false;
        }


        bool reporEstoque(int quantidade) {
            if(quantidade > 0) {
                setQuantidadeEstoque(quantidadeEstoque + quantidade);
                return true;
            }
            return false;
        }

        bool ehMaisBaratoQue(double valorLimite) const {
            if(preco < valorLimite) {
                return true;
            }
            return false;
        }

        static void exibirTotalProdutos() {
            std::cout << "Total de produtos criados: " << totalProdutos << std::endl;
        }
};

int Produto::totalProdutos = 0;

int main(){

    Produto produto1("Sabão em pó", 123, 10.50, 100);
    std::cout << "Produto criado com sucesso!  (saida da questao 1)" << std::endl;

    produto1.exibirInformacoes();
    std::cout << "(saida da questao 2)" << std::endl;

    Produto produto2;
    produto2.setQuantidadeEstoque(-5);
    std::cout << "Quantidade em estoque do produto 2: " << produto2.getQuantidadeEstoque() << std::endl;
    produto2.setQuantidadeEstoque(20);
    std::cout << "Quantidade em estoque do produto 2: " << produto2.getQuantidadeEstoque() << std::endl;

    Produto produto3;
    produto3.exibirInformacoes();

    Produto produto4;
    produto4.setQuantidadeEstoque(2);
    std::cout << "Quantidade em estoque do produto 4: " << produto4.getQuantidadeEstoque() << std::endl;
    produto4.vender(1);
    std::cout << "Quantidade em estoque do produto 4: " << produto4.getQuantidadeEstoque() << std::endl;
    produto4.vender(1);
    std::cout << "Quantidade em estoque do produto 4: " << produto4.getQuantidadeEstoque() << std::endl;
    produto4.vender(1);
    std::cout << "Quantidade em estoque do produto 4: " << produto4.getQuantidadeEstoque() << std::endl;

    produto4.reporEstoque(10);
    produto4.temEstoque();

    Produto produto[5] = {
        Produto("Arroz", 1, 5.0, 10),
        Produto("Feijão", 2, 7.0, 5),
        Produto("Macarrão", 3, 3.0, 20),
        Produto("Óleo", 4, 6.0, 15),
        Produto("Açúcar", 5, 4.0, 8)
    };

    double patrimonio = 0.0;
    for(int i = 0; i < 5; i++) {
        produto[i].exibirInformacoes();
        patrimonio += produto[i].getPreco() * produto[i].getQuantidadeEstoque();
    }
    std::cout << "Patrimônio total: " << patrimonio << std::endl;

    for(int i = 0; i < 5; i++) {
        if(produto[i].ehMaisBaratoQue(4.5)) {
            std::cout << "O produto " << produto[i].getNome() << " é mais barato que 4.5" << std::endl;
        } else {
            std::cout << "O produto " << produto[i].getNome() << " não é mais barato que 4.5" << std::endl;
        }
    }

    Produto::exibirTotalProdutos();

    {
        Produto produtoTemporario("Produto Temporário", 999, 99.99, 1);
        std::cout << "Produto temporário criado." << std::endl;
        std::cout << "Saindo do escopo do produto temporário" << std::endl;
    }

    Produto::exibirTotalProdutos();
    std::cout << "Patrimônio total: " << patrimonio << std::endl;



    return 0;
}