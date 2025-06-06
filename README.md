# Installation automatique du projet PepinPHP (Windows)

Ce programme C automatise l’installation et la configuration du projet PepinPHP sur Windows. Il effectue les opérations suivantes :

- Demande le nom du projet
- Supprime un ancien dossier du projet sur le bureau s'il existe
- Clone le dépôt Git officiel dans un dossier temporaire
- Renomme ce dossier avec le nom choisi
- Renomme le fichier `env.txt` en `.env` dans le dossier `core`
- Ouvre le projet dans Visual Studio Code
- Lance un serveur PHP local et ouvre la page `index.php` dans le navigateur

---

## Code source principal

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char projectName[256];
  printf("Entrez le nom du projet (ex: WebSiteMaker) : ");
  fgets(projectName, sizeof(projectName), stdin);

  // Enlever le retour chariot final
  size_t len = strlen(projectName);
  if (len > 0 && projectName[len - 1] == '\n')
  {
    projectName[len - 1] = '\0';
  }

  if (strlen(projectName) == 0)
  {
    strcpy(projectName, "PepinPHPv4");
  }

  // Supprimer un ancien dossier PepinPHP s'il existe
  system("cd %USERPROFILE%\\Desktop && rmdir /s /q PepinPHPv4");

  // Cloner le dépôt
  char gitCmd[512];
  snprintf(gitCmd, sizeof(gitCmd),
           "cd %%USERPROFILE%%\\Desktop && git clone https://github.com/WebSiteMaker24/PepinPHPv4.git PepinPHPTemp");
  system(gitCmd);

  // Renommer le dossier cloné avec le nom du projet
  char renameCmd[512];
  snprintf(renameCmd, sizeof(renameCmd),
           "cd %%USERPROFILE%%\\Desktop && ren PepinPHPTemp %s", projectName);
  system(renameCmd);

  // Renommer le fichier env.txt en .env
  char renameEnvCmd[512];
  snprintf(renameEnvCmd, sizeof(renameEnvCmd),
           "cd %%USERPROFILE%%\\Desktop\\%s\\core && if exist env.txt ren env.txt .env", projectName);
  system(renameEnvCmd);

  // Ouvrir le projet dans VS Code
  char openCodeCmd[512];
  snprintf(openCodeCmd, sizeof(openCodeCmd),
           "cd %%USERPROFILE%%\\Desktop\\%s && code .", projectName);
  system(openCodeCmd);

  // Ouvrir le navigateur sur index.php et lancer le serveur PHP
  char phpCmd[1024];
  snprintf(phpCmd, sizeof(phpCmd),
           "cd %%USERPROFILE%%\\Desktop\\%s && start http://localhost:8000/index.php && php -S localhost:8000 -t public_html", projectName);
  system(phpCmd);

  return 0;
}

Compilation
gcc installPepinPHP.c -o installPepinPHP.exe
Prérequis
MinGW ou TDM-GCC installé avec le dossier bin dans la variable PATH

Git installé et accessible en ligne de commande

MySQL ou MariaDB en cours d’exécution (via MAMP, XAMPP, ou service local)

Visual Studio Code installé et code dans la variable PATH

Explications détaillées
Entrée utilisateur : le programme demande un nom de projet. Si rien n’est saisi, il utilise "PepinPHPv4" par défaut.

Suppression dossier existant : il supprime l’ancien dossier PepinPHPv4 sur le bureau pour éviter les conflits.

Clonage Git : il clone le dépôt officiel dans un dossier temporaire PepinPHPTemp.

Renommage du dossier : PepinPHPTemp est renommé avec le nom choisi.

Renommage du fichier .env : dans le dossier core, si un fichier env.txt existe, il est renommé .env (format attendu pour la configuration).

Ouverture dans VS Code : le dossier du projet est ouvert automatiquement dans VS Code.

Lancement du serveur et navigateur : un serveur PHP local démarre sur le port 8000, et le navigateur ouvre automatiquement la page d’accueil.

Utilisation
Compiler puis exécuter le programme (installPepinPHP.exe).

Suivre les instructions pour entrer un nom de projet.

Le reste est automatisé.

Si tu souhaites, je peux aussi t’aider à créer un script PowerShell ou un batch Windows pour faire la même chose sans compiler.

Bon développement !
