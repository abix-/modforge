// Address: 0x14002f200
// Ghidra name: FUN_14002f200
// ============ 0x14002f200 FUN_14002f200 (size=249) ============


undefined8 FUN_14002f200(longlong param_1)



{

  undefined8 uVar1;

  undefined1 uVar2;

  undefined8 uVar3;

  longlong lVar4;

  int iVar5;

  longlong lVar6;

  undefined1 local_res8 [8];

  

  FUN_1400d0a00(param_1,0);

  lVar4 = *(longlong *)(param_1 + 0x130);

  iVar5 = 0;

  if (*(longlong *)(param_1 + 0x138) - lVar4 >> 3 != 0) {

    lVar6 = 0;

    do {

      if (*(longlong *)(lVar6 + lVar4) != *(longlong *)(param_1 + 0x148)) {

        uVar1 = *(undefined8 *)(lVar6 + lVar4);

        uVar3 = FUN_1400c57a0(local_res8,*(longlong *)(param_1 + 0x78) + 0x30,0);

        FUN_1400b6610(uVar1,uVar3);

        lVar4 = *(longlong *)(lVar6 + *(longlong *)(param_1 + 0x130));

        uVar2 = FUN_1400c66c0();

        *(undefined1 *)(lVar4 + 0x1a) = uVar2;

      }

      lVar4 = *(longlong *)(param_1 + 0x130);

      iVar5 = iVar5 + 1;

      lVar6 = lVar6 + 8;

    } while ((ulonglong)(longlong)iVar5 < (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar4 >> 3));

  }

  FUN_1400cd5a0(param_1,CONCAT71((int7)((ulonglong)lVar4 >> 8),1));

  FUN_1400ce540(param_1,0,0);

  lVar4 = *(longlong *)(param_1 + 0x260);

  if (lVar4 != *(longlong *)(param_1 + 0x268)) {

    *(longlong *)(param_1 + 0x268) = lVar4;

  }

  *(undefined8 *)(param_1 + 0x250) = 0;

  return CONCAT71((int7)((ulonglong)lVar4 >> 8),1);

}




