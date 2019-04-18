/* shutdown.c
 *
 * This is a SUID CGI program intended to safely shutdown portable,
 * headless server appliances (such as a RaspberryPi).  Any security,
 * if required is presumed to be provide

d at a higher level.
 *
 * To install into the default apache cgi-bin directory on Raspbian
 * run:
 *
 *   make install
 *
 * To install into a different directory set the CGIBIN variable.
 *
 * Copyright (c) 2016-2019 James Klassen
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */




#include<stdio.h>
#include<stdlib.h>

int main()
{
  int err;

  puts("Content-type: text/plain\n");
  puts("Shutting down Mini-Compass, please wait for the green lights to stop flashing before disconnecting power.");

  fflush(stdout);
  fclose(stdout);

  err = system("/sbin/shutdown -P now");
  if(err != 0)
    printf("Shutdown failed with error code %d", err);
  if(err = -1)
    err = 127;
  return err;
}
