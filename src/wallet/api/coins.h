#ifndef FEATHER_COINS_H
#define FEATHER_COINS_H

#include "wallet/api/wallet2_api.h"
#include "wallet/wallet2.h"

namespace Monero {

class WalletImpl;

class CoinsImpl : public Coins
{
public:
    explicit CoinsImpl(WalletImpl * wallet);
    ~CoinsImpl() override;
    int count() const override;
    CoinsInfo * coin(int index) const override;
    std::vector<CoinsInfo*> getAll() const override;
    void refresh() override;

    void setFrozen(std::string public_key) override;
    void setFrozen(int index) override;
    void thaw(std::string public_key) override;
    void thaw(int index) override;

    bool isTransferUnlocked(uint64_t unlockTime, uint64_t blockHeight) override;

    void setDescription(const std::string &public_key, const std::string &description) override;

private:
    WalletImpl *m_wallet;
    std::vector<CoinsInfo*> m_rows;
    mutable boost::shared_mutex   m_rowsMutex;
};

}

namespace Bitmonero = Monero;

#endif //FEATHER_COINS_H
