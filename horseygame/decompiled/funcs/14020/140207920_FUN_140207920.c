// Address: 0x140207920
// Ghidra name: FUN_140207920
// ============ 0x140207920 FUN_140207920 (size=150) ============


void FUN_140207920(char *param_1)



{

  longlong lVar1;

  int iVar2;

  

  _guard_check_icall();

  lVar1 = DAT_1403fd198;

  if (param_1 != (char *)0x0) {

    for (; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0xb8)) {

      if ((((*(longlong *)(lVar1 + 0x68) != 0) && (*(char *)(lVar1 + 0x9a) == '\0')) &&

          (*(char *)(lVar1 + 0x54) != '\0')) &&

         ((*(char **)(lVar1 + 0x28) != (char *)0x0 &&

          (iVar2 = strcmp(param_1,*(char **)(lVar1 + 0x28)), iVar2 == 0)))) {

        iVar2 = *(int *)(lVar1 + 0x8c);

        while ((iVar2 != 0 && (*(undefined4 **)(lVar1 + 0x90) != (undefined4 *)0x0))) {

          FUN_140208230(lVar1,**(undefined4 **)(lVar1 + 0x90));

          iVar2 = *(int *)(lVar1 + 0x8c);

        }

      }

    }

  }

  return;

}




