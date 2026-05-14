// Address: 0x140264c60
// Ghidra name: FUN_140264c60
// ============ 0x140264c60 FUN_140264c60 (size=597) ============


byte FUN_140264c60(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  bool bVar3;

  int iVar4;

  ulonglong uVar5;

  char cVar6;

  longlong lVar7;

  longlong *plVar8;

  undefined1 local_68 [64];

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  bVar3 = false;

  iVar4 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_68,0x40,*(undefined4 *)(lVar1 + 0x14))

  ;

  while (0 < iVar4) {

    *(undefined4 *)(lVar1 + 0x14) = 0;

    FUN_1402677e0(lVar1,local_68,iVar4);

    iVar4 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_68,0x40,

                          *(undefined4 *)(lVar1 + 0x14));

  }

  uVar5 = FUN_140149350();

  if ((*(ulonglong *)(lVar1 + 8) != 0) && (*(ulonglong *)(lVar1 + 8) <= uVar5)) {

    *(undefined8 *)(lVar1 + 8) = 0;

    bVar3 = true;

  }

  plVar8 = (longlong *)(lVar1 + 0x18);

  lVar7 = 8;

  do {

    lVar2 = *plVar8;

    if (lVar2 != 0) {

      cVar6 = *(char *)(lVar2 + 0x14);

      if ((cVar6 != '\0') && (*(longlong *)(lVar2 + 0x28) + 1000U <= uVar5)) {

        FUN_14012e2e0(7,"GIP: Reliable message transfer failed");

        cVar6 = '\0';

        *(undefined1 *)(lVar2 + 0x14) = 0;

      }

      if (bVar3) {

LAB_140264d9f:

        if (*(char *)(lVar1 + 0x11) == '\0') {

          FUN_140268010(lVar2);

          FUN_140267b60(lVar2);

        }

        else {

          FUN_140267e50(lVar2,7);

        }

        bVar3 = false;

      }

      else if (((*(int *)(lVar2 + 0x38) == 3) && (*(ulonglong *)(lVar2 + 0x40) <= uVar5)) &&

              (cVar6 != '\x04')) {

        if (2 < *(int *)(lVar2 + 0x48)) goto LAB_140264d9f;

        FUN_14012e2e0(7,"GIP: Retrying metadata request");

        *(int *)(lVar2 + 0x48) = *(int *)(lVar2 + 0x48) + 1;

        *(ulonglong *)(lVar2 + 0x40) = uVar5 + 500;

        FUN_140267e80(lVar2,4,0,0,0);

      }

      FUN_1402681b0(lVar2);

    }

    plVar8 = plVar8 + 1;

    lVar7 = lVar7 + -1;

    if (lVar7 == 0) {

      if ((iVar4 < 0) && (0 < *(int *)(param_1 + 0x8c))) {

        if (*(longlong *)(lVar1 + 0x18) != 0) {

          FUN_140208230(param_1,*(undefined4 *)(*(longlong *)(lVar1 + 0x18) + 0xc));

        }

        if (*(longlong *)(lVar1 + 0x20) != 0) {

          FUN_140208230(param_1,*(undefined4 *)(*(longlong *)(lVar1 + 0x20) + 0xc));

        }

        if (*(longlong *)(lVar1 + 0x28) != 0) {

          FUN_140208230(param_1,*(undefined4 *)(*(longlong *)(lVar1 + 0x28) + 0xc));

        }

        if (*(longlong *)(lVar1 + 0x30) != 0) {

          FUN_140208230(param_1,*(undefined4 *)(*(longlong *)(lVar1 + 0x30) + 0xc));

        }

        if (*(longlong *)(lVar1 + 0x38) != 0) {

          FUN_140208230(param_1,*(undefined4 *)(*(longlong *)(lVar1 + 0x38) + 0xc));

        }

        if (*(longlong *)(lVar1 + 0x40) != 0) {

          FUN_140208230(param_1,*(undefined4 *)(*(longlong *)(lVar1 + 0x40) + 0xc));

        }

        if (*(longlong *)(lVar1 + 0x48) != 0) {

          FUN_140208230(param_1,*(undefined4 *)(*(longlong *)(lVar1 + 0x48) + 0xc));

        }

        if (*(longlong *)(lVar1 + 0x50) != 0) {

          FUN_140208230(param_1,*(undefined4 *)(*(longlong *)(lVar1 + 0x50) + 0xc));

        }

      }

      return (byte)((uint)iVar4 >> 0x1f) ^ 1;

    }

  } while( true );

}




