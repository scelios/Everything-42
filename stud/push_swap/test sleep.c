#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

int main()
{
    Display *dpy;
    XEvent event;
    char key[32];
    int i;
    int keycode;

    // Ouvre une connexion à l'affichage X11
    dpy = XOpenDisplay(NULL);
    if (dpy == NULL) {
        fprintf(stderr, "Impossible d'ouvrir une connexion à l'affichage\n");
        exit(1);
    }

    // Récupère le code de la touche 'a'
    keycode = XKeysymToKeycode(dpy, XStringToKeysym("a"));

    while (1) {
        XQueryKeymap(dpy, key);
        for (i = 0; i < 32; i++) {
            if (key[i] & 1 << (keycode % 8)) {
                // Commande à exécuter si la touche 'a' est active
                system(echo "Touche ou souris active");
                break;
            }
        }
    }
    XCloseDisplay(dpy);
    return 0;
}
