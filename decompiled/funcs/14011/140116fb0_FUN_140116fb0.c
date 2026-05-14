// Address: 0x140116fb0
// Ghidra name: FUN_140116fb0
// ============ 0x140116fb0 FUN_140116fb0 (size=172) ============


ulonglong FUN_140116fb0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  uint uVar1;

  int iVar2;

  undefined1 *puVar3;

  undefined8 local_res10;

  undefined8 local_res18;

  undefined8 local_res20;

  undefined1 *local_98 [2];

  undefined1 local_88 [136];

  

  local_98[0] = local_88;

  local_res10 = param_2;

  local_res18 = param_3;

  local_res20 = param_4;

  FUN_140124b00();

  uVar1 = (*(code *)PTR_FUN_1403de8b8)(local_88,0x80,param_1,&local_res10);

  if (-1 < (int)uVar1) {

    if (0x7f < uVar1) {

      local_98[0] = (undefined1 *)0x0;

      iVar2 = (*(code *)PTR_FUN_1403de8b0)(local_98,param_1,&local_res10);

      if (iVar2 < 0) goto LAB_14011703d;

    }

    (*(code *)PTR_FUN_1403dc4d0)(&DAT_14039bf30,local_98[0]);

  }

LAB_14011703d:

  puVar3 = local_88;

  if (local_98[0] != puVar3) {

    puVar3 = (undefined1 *)(*(code *)PTR_FUN_1403de4e0)();

  }

  return (ulonglong)puVar3 & 0xffffffffffffff00;

}




