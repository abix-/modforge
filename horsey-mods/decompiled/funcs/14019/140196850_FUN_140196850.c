// Address: 0x140196850
// Ghidra name: FUN_140196850
// ============ 0x140196850 FUN_140196850 (size=145) ============


void FUN_140196850(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5,undefined4 param_6,undefined1 param_7,longlong *param_8)



{

  longlong lVar1;

  undefined4 *puVar2;

  

  for (lVar1 = *param_8; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x20)) {

    param_8 = (longlong *)(lVar1 + 0x20);

  }

  puVar2 = (undefined4 *)FUN_1401841f0(0x28);

  puVar2[4] = param_5;

  puVar2[5] = param_6;

  puVar2[1] = param_2;

  puVar2[2] = param_3;

  puVar2[3] = param_4;

  *(undefined1 *)(puVar2 + 6) = param_7;

  *puVar2 = param_1;

  *(undefined8 *)(puVar2 + 8) = 0;

  *param_8 = (longlong)puVar2;

  return;

}




