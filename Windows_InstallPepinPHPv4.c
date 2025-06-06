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

/*
Compilation (Windows) :
  gcc installPepinPHP.c -o installPepinPHP.exe

Prérequis :
- MinGW installé (ou TDM-GCC)
- Le dossier "bin" de GCC dans le PATH
- MySQL ou MariaDB installé et en cours d’exécution (ex: via MAMP, XAMPP, ou service local)
- Le fichier .exe pourra ensuite être lancé par double-clic
*/
