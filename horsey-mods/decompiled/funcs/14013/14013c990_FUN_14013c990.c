// Address: 0x14013c990
// Ghidra name: FUN_14013c990
// ============ 0x14013c990 FUN_14013c990 (size=300) ============


int FUN_14013c990(undefined8 param_1,undefined1 param_2)



{

  char cVar1;

  int iVar2;

  undefined1 *puVar3;

  undefined1 *puVar4;

  longlong lVar5;

  size_t sVar6;

  longlong lVar7;

  undefined1 *puVar8;

  int iVar9;

  longlong local_res18 [2];

  

  iVar9 = 0;

  puVar3 = (undefined1 *)FUN_14012c500(param_1,local_res18,param_2);

  if (puVar3 != (undefined1 *)0x0) {

    FUN_140159d30();

    FUN_14013c7b0();

    puVar8 = puVar3;

    if (puVar3 < puVar3 + local_res18[0]) {

      do {

        puVar4 = (undefined1 *)thunk_FUN_1402c9190(puVar8,10);

        if (puVar4 == (undefined1 *)0x0) {

          puVar4 = puVar3 + local_res18[0];

        }

        else {

          *puVar4 = 0;

        }

        lVar5 = thunk_FUN_1402c9340(puVar8,"platform:");

        if (lVar5 != 0) {

          sVar6 = strlen("platform:");

          lVar5 = lVar5 + sVar6;

          lVar7 = thunk_FUN_1402c9190(lVar5,0x2c);

          if (((lVar7 != 0) && (cVar1 = FUN_140140ad0(lVar5,lVar7 - lVar5), cVar1 != '\0')) &&

             (iVar2 = FUN_14013c930(puVar8), 0 < iVar2)) {

            iVar9 = iVar9 + 1;

          }

        }

        puVar8 = puVar4 + 1;

      } while (puVar4 + 1 < puVar3 + local_res18[0]);

    }

    FUN_14013c640();

    FUN_14015bb10();

    FUN_1401841e0(puVar3);

    return iVar9;

  }

  FUN_14012e850("Could not allocate space to read DB into memory");

  return -1;

}




