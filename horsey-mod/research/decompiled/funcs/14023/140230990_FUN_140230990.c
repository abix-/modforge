// Address: 0x140230990
// Ghidra name: FUN_140230990
// ============ 0x140230990 FUN_140230990 (size=436) ============


undefined4 FUN_140230990(undefined8 *param_1)



{

  longlong *plVar1;

  undefined *puVar2;

  undefined *puVar3;

  int iVar4;

  longlong *plVar5;

  longlong lVar6;

  HANDLE pvVar7;

  undefined4 *puVar8;

  uint uVar9;

  

  plVar5 = (longlong *)FUN_1401841a0(1,0x28);

  if (plVar5 == (longlong *)0x0) {

    return 0;

  }

  FUN_140139010(plVar5 + 4,0);

  lVar6 = FUN_140179a30();

  *plVar5 = lVar6;

  if (lVar6 != 0) {

    lVar6 = FUN_140179a30();

    plVar5[1] = lVar6;

    if (lVar6 != 0) {

      pvVar7 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);

      plVar5[2] = (longlong)pvVar7;

      if (pvVar7 == (HANDLE)0x0) {

        FUN_1401a9ed0("CreateEventW");

      }

      else {

        uVar9 = 0;

        plVar1 = plVar5 + 3;

        iVar4 = (*DAT_1403fdd60)(300,0,0x80,0x80,plVar1);

        if (iVar4 < 0) {

          FUN_1401a9ef0("CreateIoRing",iVar4);

        }

        else {

          iVar4 = (*DAT_1403fdd88)(*plVar1,plVar5[2]);

          if (iVar4 < 0) {

            FUN_1401a9ef0("SetIoRingCompletionEvent",iVar4);

          }

          else {

            puVar8 = &DAT_1403580e8;

            while (iVar4 = (*DAT_1403fdd58)(*plVar1,*puVar8), puVar2 = PTR_FUN_140358058, iVar4 != 0

                  ) {

              uVar9 = uVar9 + 1;

              puVar8 = puVar8 + 1;

              if (4 < uVar9) {

                *param_1 = PTR_FUN_140358050;

                param_1[1] = puVar2;

                puVar2 = PTR_FUN_140358068;

                param_1[2] = PTR_FUN_140358060;

                param_1[3] = puVar2;

                puVar3 = PTR_FUN_140358078;

                puVar2 = PTR_FUN_140358070;

                param_1[6] = plVar5;

                param_1[4] = puVar2;

                param_1[5] = puVar3;

                return 1;

              }

            }

            FUN_14012e850("Created IoRing doesn\'t support op %u",(&DAT_1403580e8)[(int)uVar9]);

          }

        }

      }

    }

  }

  if (plVar5[3] != 0) {

    (*DAT_1403fdd78)();

  }

  if ((HANDLE)plVar5[2] != (HANDLE)0x0) {

    CloseHandle((HANDLE)plVar5[2]);

  }

  if (*plVar5 != 0) {

    FUN_140179b30();

  }

  if (plVar5[1] != 0) {

    FUN_140179b30();

  }

  FUN_1401841e0(plVar5);

  return 0;

}




