package ru.perevoshchikov.springcourse.Convoy.containers;

import java.util.Iterator;

class Entry<K, V> {
    private final Pair<K, V> pair;

    public Entry(K key, V value) {
        pair = new Pair<>(key, value);
    }

    public K getKey() {
        return pair.getFirst();
    }

    public void setKey(K key) {
        pair.setFirst(key);
    }

    public V getValue() {
        return pair.getSecond();
    }

    public void setValue(V value) {
        pair.setSecond(value);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Entry<?, ?> entry = (Entry<?, ?>) o;

        return getKey().equals(entry.getKey());
    }

    @Override
    public int hashCode() {
        return getKey().hashCode();
    }
}

public class Map<K, V> implements Iterable<Entry<K, V>> {

    private final List<Entry<K, V>> list;

    public Map() {
        list = new List<>();
    }

    public boolean add(K key, V value) {
        Entry<K, V> entry = new Entry<>(key, value);
        if (getEntry(key) == null) {
            list.add(entry);
            return true;
        }
        return false;
    }

    public V get(K key) {
        Entry<K, V> entry = getEntry(key);

        if (entry != null)
            return entry.getValue();

        return null;
    }

    private Entry<K, V> getEntry(K key) {
        return list.get(new Entry<>(key, null));
    }

    public V remove(K key) {
        Entry<K, V> removed = list.remove(new Entry<>(key, null));

        if (removed != null)
            return removed.getValue();

        return null;
    }

    public List<K> keys() {
        List<K> keys = new List<>();
        Node<Entry<K, V>> node = list.getHead();

        for (int i = 0; (i < list.getSize()) && (node != null); i++) {
            keys.add(node.getValue().getKey());
            node = node.getNext();
        }

        return keys;
    }

    public List<V> values() {
        List<V> keys = new List<>();
        Node<Entry<K, V>> node = list.getHead();

        for (int i = 0; (i < list.getSize()) && (node != null); i++) {
            keys.add(node.getValue().getValue());
            node = node.getNext();
        }

        return keys;
    }

    public int getSize() {
        return list.getSize();
    }

    @Override
    public Iterator<Entry<K, V>> iterator() {
        return list.iterator();
    }
}