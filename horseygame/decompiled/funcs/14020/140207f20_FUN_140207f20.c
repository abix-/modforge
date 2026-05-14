// Address: 0x140207f20
// Ghidra name: FUN_140207f20
// ============ 0x140207f20 FUN_140207f20 (size=116) ============


undefined4 FUN_140207f20(char *param_1)



{

  longlong lVar1;

  int iVar2;

  

  _guard_check_icall();

  lVar1 = DAT_1403fd198;

  if (param_1 != (char *)0x0) {

    for (; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0xb8)) {

      if ((((*(longlong *)(lVar1 + 0x68) != 0) && (*(char *)(lVar1 + 0x9a) == '\0')) &&

          (*(char *)(lVar1 + 0x54) == '\0')) &&

         ((*(char **)(lVar1 + 0x28) != (char *)0x0 &&

          (iVar2 = strcmp(param_1,*(char **)(lVar1 + 0x28)), iVar2 == 0)))) {

        return 1;

      }

    }

  }

  return 0;

}




