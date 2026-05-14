// Address: 0x1401ff0c0
// Ghidra name: FUN_1401ff0c0
// ============ 0x1401ff0c0 FUN_1401ff0c0 (size=323) ============


void FUN_1401ff0c0(longlong param_1,longlong param_2)



{

  undefined4 *puVar1;

  longlong lVar2;

  longlong lVar3;

  undefined8 in_stack_ffffffffffffffa0;

  undefined4 uVar4;

  undefined8 local_48;

  undefined8 local_40;

  undefined8 local_38;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  

  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);

  lVar2 = *(longlong *)(param_2 + 0x138);

  lVar3 = *(longlong *)(param_1 + 0x2e0);

  if (lVar2 != 0) {

    FUN_1401f9dc0(lVar3);

    puVar1 = (undefined4 *)(lVar2 + 0x20);

    FUN_1401fd560(lVar3,0x19a0,0x1000,0x1480,0x1000,CONCAT44(uVar4,7),*(undefined8 *)(lVar2 + 8),

                  puVar1);

    local_2c = 1;

    local_48 = 0;

    local_40 = 0;

    local_30 = 0;

    local_38 = 1;

    local_28 = *(undefined4 *)(lVar2 + 0x60);

    local_24 = *(undefined4 *)(lVar2 + 100);

    local_20 = 0;

    local_1c = *(undefined4 *)(lVar2 + 0x68);

    local_18 = *(undefined4 *)(lVar2 + 0x6c);

    local_14 = 1;

    (*DAT_1403fcef8)(*(undefined8 *)(lVar3 + 0x698),*(undefined8 *)(lVar2 + 0x48),

                     *(undefined8 *)(lVar2 + 8),*puVar1,1,&local_48);

    FUN_1401fd560(lVar3,0x1000,0x20,0x1000,0x80,5,*(undefined8 *)(lVar2 + 8),puVar1);

    FUN_1401fabf0(lVar3);

    FUN_1401f98d0(lVar3,lVar2 + 0x40);

  }

  return;

}




