// Address: 0x1402087d0
// Ghidra name: FUN_1402087d0
// ============ 0x1402087d0 FUN_1402087d0 (size=451) ============


void FUN_1402087d0(void)



{

  undefined8 *puVar1;

  char cVar2;

  undefined8 *puVar3;

  longlong lVar4;

  longlong lVar5;

  undefined8 *puVar6;

  uint uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  

  FUN_140159d30();

  lVar4 = DAT_1403fd198;

  if (DAT_1403fd1ac != '\0') {

    FUN_140208d30();

    DAT_1403fd1ac = '\0';

    lVar4 = DAT_1403fd198;

  }

  for (; lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0xb8)) {

    if (*(longlong *)(lVar4 + 0xb0) == 0) {

      *(undefined1 *)(lVar4 + 0x98) = 0;

    }

  }

  if ((0 < DAT_1403fd1a4) &&

     (puVar3 = (undefined8 *)FUN_140193020(0,0), puVar6 = puVar3, puVar3 != (undefined8 *)0x0)) {

    do {

      lVar4 = FUN_140207dd0(*puVar6,*(undefined2 *)(puVar6 + 1),

                            *(undefined2 *)((longlong)puVar6 + 10));

      if (lVar4 == 0) {

        FUN_140206f60(puVar6,0,0);

      }

      else {

        *(undefined1 *)(lVar4 + 0x98) = 1;

        cVar2 = FUN_140208390(lVar4);

        if (cVar2 != '\0') {

          FUN_1402084f0(lVar4,puVar6[2]);

        }

      }

      puVar1 = puVar6 + 9;

      puVar6 = (undefined8 *)*puVar1;

    } while ((undefined8 *)*puVar1 != (undefined8 *)0x0);

    FUN_140193180(puVar3);

  }

  lVar4 = DAT_1403fd198;

  while (lVar5 = lVar4, lVar5 != 0) {

    lVar4 = *(longlong *)(lVar5 + 0xb8);

    if ((*(char *)(lVar5 + 0x98) == '\0') ||

       ((((*(longlong *)(lVar5 + 0x68) != 0 || (*(longlong *)(lVar5 + 0xb0) != 0)) &&

         (*(int *)(lVar5 + 0x8c) == 0)) && (*(longlong *)(lVar5 + 0x80) == 0)))) {

      lVar5 = *(longlong *)(lVar5 + 0xa0);

      if (lVar5 == 0) {

        FUN_140207680();

        DAT_1403fd190 = 0;

      }

      else {

        uVar8 = 0;

        uVar9 = 0;

        if (0 < *(int *)(lVar5 + 0xa8)) {

          do {

            FUN_140207680(*(undefined8 *)(*(longlong *)(lVar5 + 0xb0) + uVar9));

            uVar7 = (int)uVar8 + 1;

            uVar8 = (ulonglong)uVar7;

            uVar9 = uVar9 + 8;

          } while ((int)uVar7 < *(int *)(lVar5 + 0xa8));

        }

        FUN_140207680(lVar5);

        DAT_1403fd190 = 0;

        lVar4 = DAT_1403fd198;

      }

    }

    else if ((*(char *)(lVar5 + 0x9a) != '\0') && (*(longlong *)(lVar5 + 0xa0) != 0)) {

      FUN_140207680();

      lVar4 = DAT_1403fd198;

    }

  }

  do {

    cVar2 = FUN_140207460();

  } while (cVar2 != '\0');

  FUN_14015bb10();

  return;

}




