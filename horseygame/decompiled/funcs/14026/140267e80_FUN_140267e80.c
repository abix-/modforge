// Address: 0x140267e80
// Ghidra name: FUN_140267e80
// ============ 0x140267e80 FUN_140267e80 (size=100) ============


void FUN_140267e80(undefined8 *param_1,ulonglong param_2,byte param_3,undefined8 param_4,

                  undefined4 param_5)



{

  byte bVar1;

  undefined1 uVar2;

  undefined8 uVar3;

  

  uVar3 = *param_1;

  bVar1 = *(byte *)(param_1 + 1);

  uVar2 = FUN_140267f50(param_1,param_2,1);

  FUN_140267d00(uVar3,param_2 & 0xff,param_3 | bVar1 | 0x20,uVar2,param_4,param_5,0,0,0);

  return;

}




