#ifndef IPRODUTO_HPP
#define IPRODUTO_HPP

class IProduto {
public:
    virtual void exibirProduto() const = 0;
    virtual ~IProduto() = default;
};

#endif // IPRODUTO_HPP
