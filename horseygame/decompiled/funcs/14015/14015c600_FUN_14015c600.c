// Address: 0x14015c600
// Ghidra name: FUN_14015c600
// ============ 0x14015c600 FUN_14015c600 (size=433) ============


longlong *

FUN_14015c600(undefined8 param_1,undefined1 param_2,longlong *param_3,longlong param_4,

             undefined8 param_5)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  longlong *plVar4;

  longlong lVar5;

  

  FUN_14017caa0(DAT_1403fc128);

  iVar2 = FUN_140138fe0(&DAT_1403fc170);

  FUN_14017cae0(DAT_1403fc128);

  if ((iVar2 == 0) && (plVar4 = (longlong *)FUN_1401841a0(1,0xd8), plVar4 != (longlong *)0x0)) {

    lVar5 = FUN_14012f0d0(param_1);

    plVar4[9] = lVar5;

    if (lVar5 != 0) {

      lVar5 = FUN_140179a30();

      *plVar4 = lVar5;

      if (lVar5 != 0) {

        lVar5 = FUN_140160230();

        plVar4[1] = lVar5;

        if (lVar5 != 0) {

          FUN_140139010((longlong)plVar4 + 0x8c,0);

          FUN_140139010(plVar4 + 0x12,0);

          *(undefined1 *)((longlong)plVar4 + 0x94) = param_2;

          plVar4[0xc] = *param_3;

          *(int *)(plVar4 + 0xd) = (int)param_3[1];

          plVar4[0xf] = *param_3;

          *(int *)(plVar4 + 0x10) = (int)param_3[1];

          uVar3 = FUN_14015e620((int)plVar4[0xd]);

          *(undefined4 *)((longlong)plVar4 + 0x84) = uVar3;

          uVar3 = FUN_14015e760((int)plVar4[0xc]);

          *(undefined4 *)(plVar4 + 0x11) = uVar3;

          plVar4[0xb] = param_4;

          uVar3 = FUN_14015c250(param_2,0);

          *(undefined4 *)(plVar4 + 10) = uVar3;

          FUN_14017cab0(DAT_1403fc128);

          cVar1 = FUN_1401ab100(DAT_1403fc130,(int)plVar4[10],plVar4,0);

          if (cVar1 == '\0') {

            FUN_140160350(plVar4[1]);

            FUN_140179b30(*plVar4);

            FUN_1401841e0(plVar4[9]);

            FUN_1401841e0(plVar4);

            plVar4 = (longlong *)0x0;

          }

          else {

            FUN_140138fb0(param_5,1);

          }

          FUN_14017cae0(DAT_1403fc128);

          FUN_14015d3d0(plVar4);

          return plVar4;

        }

        FUN_140179b30(*plVar4);

      }

      FUN_1401841e0(plVar4[9]);

    }

    FUN_1401841e0(plVar4);

  }

  return (longlong *)0x0;

}




