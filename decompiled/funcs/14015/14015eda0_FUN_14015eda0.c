// Address: 0x14015eda0
// Ghidra name: FUN_14015eda0
// ============ 0x14015eda0 FUN_14015eda0 (size=440) ============


int FUN_14015eda0(uint param_1,undefined8 param_2)



{

  char cVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  int *piVar7;

  longlong local_res18 [2];

  

  lVar5 = FUN_14015e610();

  if (lVar5 == 0) {

    FUN_14012e850("Audio subsystem is not initialized");

    return 0;

  }

  if (param_1 < 0xfffffffe) {

    local_res18[0] = 0;

    cVar2 = '\0';

    cVar1 = FUN_14015ec10(param_1);

    if (cVar1 == '\0') {

      lVar6 = FUN_14015cb20(param_1,local_res18);

      lVar5 = local_res18[0];

      if (lVar6 != 0) {

        cVar2 = *(char *)(lVar6 + 0x20);

      }

      goto LAB_14015ee1c;

    }

  }

  else {

    cVar2 = '\x01';

  }

  lVar5 = FUN_14015cd00(param_1);

LAB_14015ee1c:

  iVar4 = 0;

  if (lVar5 != 0) {

    if ((cVar2 == '\0') && (iVar3 = FUN_140138fe0(lVar5 + 0x90), iVar3 != 0)) {

      FUN_14012e850("Device was already lost and can\'t accept new opens");

      FUN_14015d3e0(lVar5);

    }

    else {

      piVar7 = (int *)FUN_1401841a0(1,0x48);

      if (piVar7 != (int *)0x0) {

        cVar1 = FUN_14015cef0(lVar5,param_2);

        if (cVar1 == '\0') {

          FUN_1401841e0(piVar7);

          FUN_14015d3e0(lVar5);

          return 0;

        }

        FUN_14015d3d0(lVar5);

        FUN_140139010(piVar7 + 4,0);

        iVar4 = FUN_14015c250(*(undefined1 *)(lVar5 + 0x94),1);

        *piVar7 = iVar4;

        *(longlong *)(piVar7 + 2) = lVar5;

        piVar7[5] = 0x3f800000;

        *(char *)(piVar7 + 8) = cVar2;

        *(undefined8 *)(piVar7 + 0xe) = *(undefined8 *)(lVar5 + 0xd0);

        if (*(longlong *)(lVar5 + 0xd0) != 0) {

          *(int **)(*(longlong *)(lVar5 + 0xd0) + 0x40) = piVar7;

        }

        *(int **)(lVar5 + 0xd0) = piVar7;

        FUN_14015fec0(lVar5);

      }

      FUN_14015d3e0(lVar5);

      if (iVar4 != 0) {

        FUN_14017cab0(DAT_1403fc128);

        cVar2 = FUN_1401ab100(DAT_1403fc138,iVar4,piVar7,0);

        FUN_14017cae0(DAT_1403fc128);

        if (cVar2 == '\0') {

          FUN_14015ddd0(iVar4);

          iVar4 = 0;

        }

      }

    }

  }

  return iVar4;

}




