// Address: 0x140280f50
// Ghidra name: FUN_140280f50
// ============ 0x140280f50 FUN_140280f50 (size=85) ============


void FUN_140280f50(undefined8 param_1,undefined8 param_2,longlong param_3)



{

  byte bVar1;

  undefined8 uVar2;

  byte bVar3;

  

  bVar1 = *(byte *)(param_3 + 0xb) >> 4;

  bVar3 = *(byte *)(param_3 + 0xb) & 0xf;

  if (bVar1 == 0) {

    uVar2 = 1;

  }

  else {

    if (bVar1 != 1) {

      if (bVar1 != 2) {

        FUN_14015af40(param_1,0,0);

        return;

      }

      FUN_14015af40(param_1,4,100);

      return;

    }

    uVar2 = 3;

  }

  FUN_14015af40(param_1,uVar2,((uint)bVar3 + (uint)bVar3 * 4) * 4);

  return;

}




