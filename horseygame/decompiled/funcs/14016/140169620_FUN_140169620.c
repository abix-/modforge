// Address: 0x140169620
// Ghidra name: FUN_140169620
// ============ 0x140169620 FUN_140169620 (size=103) ============


undefined4 FUN_140169620(longlong param_1,char *param_2)



{

  int iVar1;

  ulonglong uVar2;

  

  uVar2 = 0;

  if (*(longlong *)(param_1 + 0x380) != 0) {

    do {

      iVar1 = strcmp(param_2,*(char **)(*(longlong *)(param_1 + 0x378) + uVar2 * 8));

      if (iVar1 == 0) {

        return 1;

      }

      uVar2 = uVar2 + 1;

    } while (uVar2 < *(ulonglong *)(param_1 + 0x380));

  }

  return 0;

}




