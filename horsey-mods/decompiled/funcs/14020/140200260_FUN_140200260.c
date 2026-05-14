// Address: 0x140200260
// Ghidra name: FUN_140200260
// ============ 0x140200260 FUN_140200260 (size=91) ============


void FUN_140200260(longlong param_1,longlong param_2)



{

  undefined1 uVar1;

  undefined4 uVar2;

  undefined8 uVar3;

  

  uVar1 = *(undefined1 *)(param_2 + 0x14);

  uVar2 = *(undefined4 *)(param_1 + 0x2c);

  uVar3 = *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x138);

  FUN_1401486f0(uVar3,*(undefined1 *)(param_2 + 0x11),*(undefined1 *)(param_2 + 0x12),

                *(undefined1 *)(param_2 + 0x13));

  FUN_1401483d0(uVar3,uVar1);

  FUN_140148450(uVar3,uVar2);

  return;

}




