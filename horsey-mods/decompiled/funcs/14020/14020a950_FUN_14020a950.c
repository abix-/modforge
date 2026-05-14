// Address: 0x14020a950
// Ghidra name: FUN_14020a950
// ============ 0x14020a950 FUN_14020a950 (size=366) ============


void FUN_14020a950(void)



{

  char cVar1;

  longlong lVar2;

  uint uVar3;

  char *pcVar4;

  undefined8 uVar5;

  uint uVar6;

  longlong *plVar7;

  bool bVar8;

  

  lVar2 = DAT_1403fd1c8;

  bVar8 = false;

  uVar6 = 0;

  if ((DAT_1403fd23d == '\0') && (plVar7 = DAT_1403fd230, uVar3 = uVar6, 0 < DAT_1403fd238)) {

    do {

      if ((*(char *)(*plVar7 + 0x50) == '\0') && ((*(uint *)(*plVar7 + 0x10) & 0x40000000) != 0)) {

        bVar8 = true;

        break;

      }

      uVar3 = uVar3 + 1;

      plVar7 = plVar7 + 1;

    } while ((int)uVar3 < DAT_1403fd238);

  }

  DAT_1403fd23d = 1;

  if (DAT_1403e4ec9 == '\0') {

    pcVar4 = &DAT_1403fd1e3;

    do {

      if (((pcVar4[-1] != '\0') && (*pcVar4 == '\0')) && ((*(ushort *)(pcVar4 + -0xf) & 0x400) != 0)

         ) goto LAB_14020a9f1;

      uVar6 = uVar6 + 1;

      pcVar4 = pcVar4 + 0x18;

    } while (uVar6 < 4);

  }

  DAT_1403e4ec9 = 1;

  if (bVar8) {

LAB_14020a9f1:

    DAT_1403e4ec9 = 1;

    if ((DAT_1403fd1c0 != 0) && (DAT_1403fd1c8 == 0)) {

      if (*(char *)(*(longlong *)(DAT_1403fd1c0 + 0x148) + 0x38) != '\0') {

        cVar1 = *(char *)(DAT_1403fd1c0 + 0x70);

        uVar5 = FUN_140149300();

        FUN_14015ad00(uVar5,DAT_1403fd1c0,cVar1 + -1,1);

      }

      DAT_1403fd1c8 = DAT_1403fd1c0;

      DAT_1403fd1c0 = 0;

      return;

    }

  }

  else if (DAT_1403fd1c8 != 0) {

    if (*(char *)(*(longlong *)(DAT_1403fd1c8 + 0x148) + 0x38) != '\0') {

      cVar1 = *(char *)(DAT_1403fd1c8 + 0x70);

      uVar5 = FUN_140149300();

      FUN_14015ad00(uVar5,lVar2,cVar1 + -1,0);

    }

    DAT_1403fd1c8 = 0;

  }

  DAT_1403fd1c0 = 0;

  return;

}




