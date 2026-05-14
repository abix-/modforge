// Address: 0x140285420
// Ghidra name: FUN_140285420
// ============ 0x140285420 FUN_140285420 (size=96) ============


void FUN_140285420(undefined8 param_1)



{

  int iVar1;

  uint uVar2;

  undefined1 local_28;

  undefined1 local_27;

  

  if (DAT_1403fde20 != '\0') {

    uVar2 = 3;

    do {

      iVar1 = (*DAT_1403fddf8)(uVar2 & 0xff,1,&local_28);

      if (iVar1 == 0) {

        FUN_140284ff0(uVar2 & 0xff,local_27,param_1);

      }

      uVar2 = uVar2 - 1;

    } while (-1 < (int)uVar2);

  }

  return;

}




