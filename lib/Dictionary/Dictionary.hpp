#pragma once
#include <utility>
template <typename K, typename V>
struct Dictionary // 词典
{
    virtual int size() const = 0; // 当前词条总数
    virtual bool put(K, V) = 0;   // 插入词条（禁止雷同词条时可能失效）
    virtual V *get(K k) = 0;      // 读取词条
    virtual bool remove(K k) = 0; // 删除词条
};
template <typename K, typename V>
class Entry
{
private:
    K key;
    V value;

public:
    Entry() : key(), value() {}
    Entry(const K &k, const V &v) : key(k), value(v) {}
    ~Entry();
    // p = [key,value]
    Entry<K, V> &operator=(const std::pair<K, V> &p)
    {
        key = p.first;
        value = p.second;
        return *this;
    }
    K getkey() const
    {
        return key;
    }
    V getvalue() const
    {
        return value;
    }
    void setkey(const K &k) const
    {
        key = k;
    }
    K setvalue(const V &v) const
    {
        value = v;
    }
};
