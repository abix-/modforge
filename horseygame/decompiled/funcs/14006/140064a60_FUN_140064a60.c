// Address: 0x140064a60
// Ghidra name: FUN_140064a60
// ============ 0x140064a60 FUN_140064a60 (size=212) ============


undefined8 FUN_140064a60(longlong param_1)



{

  undefined8 uVar1;

  undefined8 uVar2;

  longlong lVar3;

  int iVar4;

  longlong lVar5;

  undefined1 local_res8 [8];

  

  FUN_1400d0a00(param_1,0);

  lVar3 = *(longlong *)(param_1 + 0x130);

  iVar4 = 0;

  if (*(longlong *)(param_1 + 0x138) - lVar3 >> 3 != 0) {

    lVar5 = 0;

    do {

      if (*(longlong *)(lVar5 + lVar3) != *(longlong *)(param_1 + 0x148)) {

        uVar1 = *(undefined8 *)(lVar5 + lVar3);

        uVar2 = FUN_1400c57a0(local_res8,*(longlong *)(param_1 + 0x78) + 0x30,0);

        FUN_1400b6610(uVar1,uVar2);

      }

      lVar3 = *(longlong *)(param_1 + 0x130);

      iVar4 = iVar4 + 1;

      lVar5 = lVar5 + 8;

    } while ((ulonglong)(longlong)iVar4 < (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar3 >> 3));

  }

  FUN_1400cd5a0(param_1,CONCAT71((int7)((ulonglong)lVar3 >> 8),1));

  FUN_1400ce540(param_1,0,0);

  *(undefined1 *)(param_1 + 0x324) = 0;

  *(undefined4 *)(param_1 + 0x250) = 0;

  return 1;

}




