// Address: 0x140151390
// Ghidra name: FUN_140151390
// ============ 0x140151390 FUN_140151390 (size=610) ============


longlong FUN_140151390(longlong param_1,longlong param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  char cVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  longlong lVar7;

  int *piVar8;

  undefined8 uVar9;

  int *piVar10;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar4 = FUN_1401aa7c0(param_1,2), cVar4 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    return 0;

  }

  if (*(char *)(param_1 + 0x2d8) != '\0') {

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

    return 0;

  }

  if (*(longlong *)(param_1 + 0xc0) != 0) {

    FUN_140149cf0(param_1);

    lVar7 = *(longlong *)(param_1 + 0x138);

    local_18 = *(undefined4 *)(lVar7 + 0x18);

    uStack_14 = *(undefined4 *)(lVar7 + 0x1c);

    uStack_10 = *(undefined4 *)(lVar7 + 0x20);

    uStack_c = *(undefined4 *)(lVar7 + 0x24);

    if ((param_2 != 0) && (cVar4 = FUN_140185790(param_2,&local_18,&local_18), cVar4 == '\0')) {

      FUN_14012e850("Can\'t read outside the current viewport");

      return 0;

    }

    lVar7 = (**(code **)(param_1 + 0xc0))(param_1,&local_18);

    if (lVar7 != 0) {

      uVar5 = FUN_140146bc0(lVar7);

      piVar3 = *(int **)(param_1 + 0x1f0);

      if (piVar3 != (int *)0x0) {

        uVar6 = FUN_14014f530(piVar3);

        piVar8 = (int *)FUN_140174d30(uVar6,"SDL.internal.texture.parent",0);

        piVar10 = piVar3;

        if (piVar8 != (int *)0x0) {

          piVar10 = piVar8;

        }

        iVar1 = *piVar10;

        FUN_1401752f0(uVar5,"SDL.surface.SDR_white_point",piVar3[7]);

        FUN_1401752f0(uVar5,"SDL.surface.HDR_headroom",piVar3[8]);

        iVar2 = *(int *)(lVar7 + 4);

        if (iVar2 == 0x16362004) {

          if (iVar1 != 0x16161804) {

            return lVar7;

          }

        }

        else if (iVar2 == 0x16462004) {

          if (iVar1 != 0x16261804) {

            return lVar7;

          }

        }

        else if (iVar2 == 0x16762004) {

          if (iVar1 != 0x16561804) {

            return lVar7;

          }

        }

        else {

          if (iVar2 != 0x16862004) {

            return lVar7;

          }

          if (iVar1 != 0x16661804) {

            return lVar7;

          }

        }

        *(int *)(lVar7 + 4) = iVar1;

        uVar9 = FUN_14017a950(iVar1);

        *(undefined8 *)(lVar7 + 0x38) = uVar9;

        return lVar7;

      }

      FUN_1401752f0(uVar5,"SDL.surface.SDR_white_point",*(undefined4 *)(param_1 + 0x20c));

      FUN_1401752f0(uVar5,"SDL.surface.HDR_headroom",*(undefined4 *)(param_1 + 0x210));

    }

    return lVar7;

  }

  FUN_14012e850("That operation is not supported");

  return 0;

}




