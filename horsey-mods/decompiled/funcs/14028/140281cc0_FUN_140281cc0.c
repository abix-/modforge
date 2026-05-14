// Address: 0x140281cc0
// Ghidra name: FUN_140281cc0
// ============ 0x140281cc0 FUN_140281cc0 (size=363) ============


undefined8 FUN_140281cc0(longlong param_1)



{

  char cVar1;

  longlong lVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  undefined1 local_78 [16];

  undefined8 local_68;

  undefined4 local_60;

  undefined1 local_58 [3];

  undefined1 local_55;

  undefined1 local_53;

  undefined1 local_52;

  undefined1 local_51;

  undefined1 local_50;

  undefined1 local_4f;

  undefined1 local_4e;

  char local_4b;

  char local_49;

  

  lVar2 = *(longlong *)(param_1 + 0x70);

  iVar5 = 0;

  cVar1 = *(char *)(lVar2 + 8);

  do {

    if ((cVar1 != '\0') || (0x1d < iVar5)) {

      FUN_140281f80(param_1);

      FUN_140281f20(param_1,1);

      return 1;

    }

    local_68 = 0xec05;

    local_60 = 0;

    FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_68,0xc);

    iVar4 = 0;

    while( true ) {

      FUN_1401492f0(1);

      iVar3 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_58,0x40,0);

      if (iVar3 < 0) break;

      if ((iVar3 == 0x20) && (local_49 == -0x14)) {

        *(undefined1 *)(lVar2 + 8) = local_55;

        *(ushort *)(lVar2 + 0x10) = CONCAT11(local_4e,local_4f);

        FUN_14012ef10(local_78,9,"%.2x%.2x%.2x%.2x",local_53,local_52,local_51,local_50);

        FUN_140208490(param_1,local_78);

        if (0x63ff < *(ushort *)(lVar2 + 0x10)) {

          if (local_4b == '\0') {

            *(undefined1 *)(lVar2 + 0xd) = 1;

          }

          else if (local_4b == '\x01') {

            *(undefined1 *)(lVar2 + 0xd) = 0;

          }

        }

        break;

      }

      iVar4 = iVar4 + 1;

      if (99 < iVar4) break;

    }

    iVar5 = iVar5 + 1;

    cVar1 = *(char *)(lVar2 + 8);

  } while( true );

}




