// Address: 0x140263d00
// Ghidra name: FUN_140263d00
// ============ 0x140263d00 FUN_140263d00 (size=90) ============


undefined8 FUN_140263d00(longlong param_1,int *param_2)



{

  char *pcVar1;

  byte bVar2;

  ulonglong uVar3;

  

  pcVar1 = *(char **)(param_1 + 0x70);

  _guard_check_icall();

  if (*pcVar1 == '\0') {

    bVar2 = 0;

    do {

      uVar3 = (ulonglong)bVar2;

      if (((*param_2 == *(int *)(pcVar1 + uVar3 * 4 + 4)) && (pcVar1[uVar3 + 0x14] == '\0')) &&

         (pcVar1[uVar3 + 0x48] != '\0')) {

        return 0x10;

      }

      bVar2 = bVar2 + 1;

    } while (bVar2 < 4);

  }

  return 0;

}




