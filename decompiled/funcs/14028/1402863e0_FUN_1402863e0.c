// Address: 0x1402863e0
// Ghidra name: FUN_1402863e0
// ============ 0x1402863e0 FUN_1402863e0 (size=144) ============


undefined8 FUN_1402863e0(longlong *param_1,undefined8 *param_2)



{

  int iVar1;

  longlong lVar2;

  undefined8 uVar3;

  undefined4 local_238;

  undefined8 local_234;

  undefined4 local_22c;

  undefined1 local_218 [528];

  

  if ((param_1 != (longlong *)0x0) && (param_2 != (undefined8 *)0x0)) {

    local_238 = 0x228;

    local_22c = 0;

    local_234 = 0x10;

    iVar1 = (**(code **)(*param_1 + 0x28))(param_1,0xc,&local_238);

    if (-1 < iVar1) {

      lVar2 = FUN_14012fd40(local_218);

      uVar3 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_218,lVar2 * 2 + 2);

      *param_2 = uVar3;

      FUN_14012f510(uVar3);

      return 1;

    }

  }

  return 0;

}




