// Address: 0x1401c0540
// Ghidra name: FUN_1401c0540
// ============ 0x1401c0540 FUN_1401c0540 (size=178) ============


bool FUN_1401c0540(longlong param_1,int param_2,int param_3,uint param_4)



{

  uint uVar1;

  int iVar2;

  undefined4 uVar3;

  uint uVar4;

  undefined1 local_28 [32];

  

  uVar4 = (param_4 & 1) << 2;

  uVar1 = uVar4 | 0x10;

  if ((param_4 & 2) == 0) {

    uVar1 = uVar4;

  }

  uVar4 = uVar1 | 0x20;

  if ((param_4 & 4) == 0) {

    uVar4 = uVar1;

  }

  uVar1 = uVar4 | 8;

  if ((param_4 & 0x78) == 0) {

    uVar1 = uVar4;

  }

  uVar3 = 0;

  if (param_3 - 3U < 2) {

    uVar3 = 0x10;

  }

  iVar2 = (**(code **)(param_1 + 0x978))

                    (*(undefined8 *)(param_1 + 8),

                     *(undefined4 *)(&DAT_1403e3ec0 + (longlong)param_2 * 4),(param_3 == 2) + '\x01'

                     ,0,uVar1,uVar3,local_28);

  return iVar2 == 0;

}




