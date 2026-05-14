// Address: 0x140226500
// Ghidra name: FUN_140226500
// ============ 0x140226500 FUN_140226500 (size=262) ============


undefined8 FUN_140226500(undefined8 param_1,longlong param_2)



{

  longlong lVar1;

  char cVar2;

  uint uVar3;

  undefined8 uVar4;

  int iVar5;

  undefined1 local_48 [4];

  int local_44;

  undefined8 local_28;

  

  lVar1 = *(longlong *)(param_2 + 0x80);

  uVar4 = FUN_1402261c0(param_1,lVar1);

  iVar5 = -1;

  cVar2 = FUN_140226360(param_1,uVar4,*(undefined8 *)(lVar1 + 0x40),lVar1,0xffffffff,local_48,0,0);

  while (cVar2 != '\0') {

    if ((((local_44 == 0) || (((byte)(local_44 >> 0x1c) & 0xf) == 1)) &&

        ((uVar3 = local_44 >> 0x18 & 0xf, uVar3 == 1 || ((uVar3 == 0xc || (uVar3 - 2 < 2)))))) ||

       ((local_44 == 0 || (cVar2 = FUN_140169f50(param_2,local_48), cVar2 == '\0')))) {

      FUN_1401841e0(local_28);

    }

    iVar5 = iVar5 + 1;

    cVar2 = FUN_140226360(param_1,uVar4,*(undefined8 *)(lVar1 + 0x40),lVar1,iVar5,local_48,0,0);

  }

  FUN_140227050(uVar4);

  return 1;

}




