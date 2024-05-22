#include <iostream>
#include <sstream>
#include "tddFuncs.h"
#include "WordCount.h"

using namespace std;

void testIsWordChar(){
    WordCount wc;
    assertTrue(wc.isWordChar('y'), "isWordChar('a')", __LINE__);
    assertTrue(wc.isWordChar('Z'), "isWordChar('Z')", __LINE__);
    assertTrue(!wc.isWordChar('3'), "isWordChar('1')", __LINE__);
    assertTrue(!wc.isWordChar('-'), "isWordChar('-')", __LINE__);
    assertTrue(!wc.isWordChar(' '), "isWordChar(' ')", __LINE__);
}

void testMakeValidWord() {
    WordCount wc;
    assertEquals("kalbi", wc.makeValidWord("-k12albi!"), "makeValidWord(\"-k12albi\")", __LINE__);
    assertEquals("kapitol", wc.makeValidWord("kApitOl"), "makeValidWord(\"kapitol\")", __LINE__);
    assertEquals("cold-hearted", wc.makeValidWord("cold-hearted"), "makeValidWord(\"cold-hearted\")", __LINE__);
    assertEquals("wasn't", wc.makeValidWord("wasn't"), "makeValidWord(\"wasn't\")", __LINE__);
    assertEquals("s", wc.makeValidWord("$-s'-#"), "makeValidWord(\"$-s'-#\")", __LINE__);
}

void testIncrWordCount(){
    WordCount wc;
    assertEquals(1, wc.incrWordCount("Hello"), "incrWordCount(\"Hello\")", __LINE__);
    assertEquals(2, wc.incrWordCount("Hello"), "incrWordCount(\"Hello\")", __LINE__);
    assertEquals(3, wc.incrWordCount("hello"), "incrWordCount(\"hello\")", __LINE__);
    assertEquals(1, wc.incrWordCount("world"), "incrWordCount(\"world\")", __LINE__);
}

void testDecrWordCount(){
    WordCount wc;
    wc.incrWordCount("Hello");
    wc.incrWordCount("Hello");
    assertEquals(1, wc.decrWordCount("Hello"), "decrWordCount(\"Hello\")", __LINE__);
    assertEquals(0, wc.decrWordCount("Hello"), "decrWordCount(\"Hello\")", __LINE__);
    assertEquals(-1, wc.decrWordCount("Hello"), "decrWordCount(\"Hello\")", __LINE__);
}

void testGetTotalWords(){
    WordCount wc;
    wc.incrWordCount("Uno");
    wc.incrWordCount("Dos");
    wc.incrWordCount("Tres");
    wc.incrWordCount("Quatro");
    assertEquals(4, wc.getTotalWords(), "getTotalWords()", __LINE__);
}

void testGetNumUniqueWords(){
    WordCount wc;
    wc.incrWordCount("Uno");
    wc.incrWordCount("Uno");
    wc.incrWordCount("Uno");
    wc.incrWordCount("Dos");
    wc.incrWordCount("Tres");
    wc.incrWordCount("Quatro");
    assertEquals(4, wc.getNumUniqueWords(), "getNumUniqueWords()", __LINE__);
}

void testGetWordCount(){
    WordCount wc;
    wc.incrWordCount("Uno");
    wc.incrWordCount("Uno");
    wc.incrWordCount("Uno");
    wc.incrWordCount("Dos");
    wc.incrWordCount("Tres");
    wc.incrWordCount("Quatro");
    assertEquals(3, wc.getWordCount("Uno"), "getWordCount(\"Uno\")", __LINE__);
    assertEquals(1, wc.getWordCount("Dos"), "getWordCount(\"Dos\")", __LINE__);
    assertEquals(1, wc.getWordCount("Tres"), "getWordCount(\"Tres\")", __LINE__);
    assertEquals(1, wc.getWordCount("Quatro"), "getWordCount(\"Quatro\")", __LINE__);
    assertEquals(0, wc.getWordCount("Sinco"), "getWordCount(\"Sinco\")", __LINE__);
}





int main(){
    testIsWordChar();
    testMakeValidWord();
    testGetTotalWords();
    testGetNumUniqueWords();
    testGetWordCount();
    testIncrWordCount();    
    testDecrWordCount();

    cout << "All functions went through" << endl;
    return 0;
}