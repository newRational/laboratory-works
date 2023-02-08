package ru.perevoshchikov.springcourse.Convoy.containers;

import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Spliterators;
import java.util.function.Consumer;

import java.util.stream.Stream;
import java.util.stream.StreamSupport;

class Node<T> {
    private T value;
    private Node<T> next;
    private Node<T> prev;
    public Node(T value) {
        this.value = value;
    }
    public T getValue() {
        return value;
    }

    public void setValue(T value) {
        this.value = value;
    }
    public Node<T> getNext() {
        return next;
    }
    public void setNext(Node<T> next) {
        this.next = next;
    }
    public Node<T> getPrev() {
        return prev;
    }
    public void setPrev(Node<T> prev) {
        this.prev = prev;
    }
}

public class List<T> implements Iterable<T> {
    private int size;
    private Node<T> head;
    private Node<T> tail;

    public List() {}

    public void add(T value) {
        Node<T> node = new Node<>(value);

        if (size == 0) {
            head = node;
            tail = node;
        } else {
            node.setNext(head);
            head.setPrev(node);
            head = node;
        }
        size++;
    }

    public T get(T key) {
        Node<T> node = getNode(key);

        if (node != null)
            return node.getValue();

        return null;
    }

    private Node<T> getNode(T value) {
        Node<T> node = head;

        for (int i = 0; (i < size) && node != null; i++)
            if (node.getValue().equals(value))
                return node;
            else
                node = node.getNext();

        return null;
    }

    public T remove(T value) {
        Node<T> node = getNode(value);

        if (node == null)
            return null;

        if (size == 1) {
            tail = null;
            head = null;
        } else if (head == node) {
            head = node.getNext();
            node.getNext().setPrev(null);
        } else if (tail == node) {
            tail = node.getPrev();
            node.getPrev().setNext(null);
        } else {
            node.getPrev().setNext(node.getNext());
            node.getNext().setPrev(node.getPrev());
        }

        size--;
        return node.getValue();
    }

    public Node<T> getHead() {
        return head;
    }

    public Node<T> getTail() {
        return tail;
    }

    public int getSize() {
        return size;
    }

    private class ListIterator implements Iterator<T> {
        Node<T> node;
        int nextIndex;
        ListIterator() {
            nextIndex = 0;
            node = head;
        }

        @Override
        public boolean hasNext() {
            return nextIndex < size;
        }

        @Override
        public T next() {
            T value = null;

            if (!hasNext()) throw new NoSuchElementException();

            if (node != null) {
                if (nextIndex > 0)
                    node = node.getNext();

                value = node.getValue();

                nextIndex++;
            }

            return value;
        }
    }

    @Override
    public Iterator<T> iterator() {
        return new ListIterator();
    }

    @Override
    public void forEach(Consumer<? super T> action) {
        Iterable.super.forEach(action);
    }

    public Stream<T> stream() {
        return StreamSupport.stream(Spliterators.spliteratorUnknownSize(iterator(), 0), false);
    }
}
