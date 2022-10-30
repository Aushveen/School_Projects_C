#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void){
  char * xmlString = 
  "<?xml version=\"1.0\"?>\n<catalog>\n"
  "<book id=\"bk101\">\n"
     "<author>Gambardella, Matthew</author>\n"
     "<title>XML Developer's Guide</title>\n"
     "<genre>Computer</genre>\n"
     "<price>44.95</price>\n"
     "<publish_date>2000-10-01</publish_date>\n"
     "<description>An in-depth look at creating applications with XML.</description>\n"
  "</book>\n"
  "<book id=\"bk102\">\n"
     "<author>Cormen, Stein</author>\n"
     "<title>Introduction of Algorithm, fourth edition</title>\n"
     "<genre>Computer</genre>\n"
     "<price>84.89</price>\n"
     "<publish_date>2022-04-05</publish_date>\n"
     "<description>A comprehensive update of the leading algorithms text, with new material on matchings in bipartite graphs, online algorithms, machine learning, and other topics.</description>\n"
  "</book>\n"
  "<book id=\"bk103\">\n"
     "<author>Ryan, Carl</author>\n"
     "<title>Python Programming for beginners: A Crash Course</title>\n"
     "<genre>Computer</genre>\n"
     "<price>7.11</price>\n"
     "<publish_date>2022-01-19</publish_date>\n"
     "<description>The Ultimate Python guide for beginners!</description>\n"
  "</book>\n"
  "</catalog>";
  //printf("%s\n", xmlString);
  for(int i=0; xmlString[i] != '\0'; i++)
    printf("%c", xmlString[i]);
  printf("\n");

  return 0;

}

