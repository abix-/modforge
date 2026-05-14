// Address: 0x140214d50
// Ghidra name: FUN_140214d50
// ============ 0x140214d50 FUN_140214d50 (size=168) ============


ulonglong FUN_140214d50(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  ulonglong uVar3;

  

  uVar3 = FUN_140138fe0(param_1 + 0x8c);

  if ((int)uVar3 == 0) {

    uVar3 = FUN_140138fe0(*(longlong *)(param_1 + 200) + 0x40);

    if ((int)uVar3 == 0) {

      if (*(char *)(*(longlong *)(param_1 + 200) + 0x45) == (char)uVar3) {

        uVar3 = FUN_140138fe0(param_1 + 0x90);

        if ((int)uVar3 == 0) {

          lVar1 = *(longlong *)(param_1 + 200);

          if (*(longlong *)(lVar1 + 0x10) == 0) {

            return CONCAT71((int7)((ulonglong)lVar1 >> 8),1);

          }

          if (*(char *)(lVar1 + 0x44) != '\0') {

            cVar2 = FUN_140214d10(param_1);

            return (ulonglong)(cVar2 != '\0');

          }

          return 1;

        }

      }

      else {

        (**(code **)(**(longlong **)(*(longlong *)(param_1 + 200) + 0x10) + 0x58))();

        uVar3 = FUN_140214fb0(param_1);

      }

    }

  }

  return uVar3 & 0xffffffffffffff00;

}




