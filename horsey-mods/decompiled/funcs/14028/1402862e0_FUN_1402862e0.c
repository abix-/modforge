// Address: 0x1402862e0
// Ghidra name: FUN_1402862e0
// ============ 0x1402862e0 FUN_1402862e0 (size=248) ============


undefined8

FUN_1402862e0(longlong *param_1,undefined2 param_2,undefined2 param_3,undefined8 *param_4,

             longlong *param_5)



{

  int iVar1;

  undefined8 uVar2;

  longlong lVar3;

  undefined4 local_228;

  undefined8 local_224;

  undefined4 local_21c;

  undefined1 local_218 [528];

  

  if (((param_1 == (longlong *)0x0) || (param_4 == (undefined8 *)0x0)) ||

     (param_5 == (longlong *)0x0)) {

LAB_1402863b8:

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_140207c80(param_2,param_3);

    *param_4 = uVar2;

    lVar3 = FUN_140207cf0(param_2,param_3);

    *param_5 = lVar3;

    if (lVar3 == 0) {

      local_228 = 0x218;

      local_224 = 0x10;

      local_21c = 0;

      iVar1 = (**(code **)(*param_1 + 0x28))(param_1,0xe,&local_228);

      if (iVar1 < 0) goto LAB_1402863b8;

      *param_4 = 0;

      lVar3 = FUN_14012fd40(local_218);

      lVar3 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_218,lVar3 * 2 + 2);

      *param_5 = lVar3;

    }

    uVar2 = 1;

  }

  return uVar2;

}




