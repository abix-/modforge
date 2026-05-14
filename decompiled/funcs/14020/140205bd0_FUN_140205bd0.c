// Address: 0x140205bd0
// Ghidra name: FUN_140205bd0
// ============ 0x140205bd0 FUN_140205bd0 (size=452) ============


int * FUN_140205bd0(int param_1,int param_2,int param_3,int param_4)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  undefined8 uVar4;

  longlong lVar5;

  bool bVar6;

  undefined8 local_18 [2];

  

  if (param_1 < 0x3259555a) {

    if (((param_1 != 0x32595559) && (param_1 != 0x3132564e)) && (param_1 != 0x3231564e)) {

      bVar6 = param_1 == 0x32315659;

LAB_140205c25:

      if (!bVar6) {

        FUN_14012e850("Unsupported YUV format");

        return (int *)0x0;

      }

    }

  }

  else if ((param_1 != 0x55595659) && (param_1 != 0x56555949)) {

    bVar6 = param_1 == 0x59565955;

    goto LAB_140205c25;

  }

  piVar3 = (int *)FUN_1401841a0(1,0x58);

  if (piVar3 != (int *)0x0) {

    *piVar3 = param_1;

    piVar3[1] = param_2;

    piVar3[3] = param_3;

    piVar3[2] = 0;

    piVar3[4] = param_4;

    cVar1 = FUN_1401d47f0(param_1,param_3,param_4,local_18,0);

    if (cVar1 != '\0') {

      uVar4 = FUN_14017fc90();

      lVar5 = FUN_140190080(uVar4,local_18[0]);

      *(longlong *)(piVar3 + 6) = lVar5;

      if (lVar5 != 0) {

        if (param_1 < 0x3259555a) {

          if (param_1 != 0x32595559) {

            if ((param_1 == 0x3132564e) || (param_1 == 0x3231564e)) {

              piVar3[8] = param_3;

              *(longlong *)(piVar3 + 0xc) = lVar5;

              piVar3[9] = ((param_3 + 1) / 2) * 2;

              *(longlong *)(piVar3 + 0xe) = param_3 * param_4 + lVar5;

              return piVar3;

            }

            if (param_1 != 0x32315659) {

              return piVar3;

            }

LAB_140205cd6:

            piVar3[8] = param_3;

            *(longlong *)(piVar3 + 0xc) = lVar5;

            iVar2 = (param_3 + 1) / 2;

            piVar3[9] = iVar2;

            piVar3[10] = iVar2;

            *(longlong *)(piVar3 + 0xe) = param_3 * param_4 + lVar5;

            *(longlong *)(piVar3 + 0x10) =

                 (longlong)(((param_4 + 1) / 2) * iVar2) + (longlong)(param_3 * param_4) + lVar5;

            return piVar3;

          }

        }

        else if (param_1 != 0x55595659) {

          if (param_1 == 0x56555949) goto LAB_140205cd6;

          if (param_1 != 0x59565955) {

            return piVar3;

          }

        }

        *(longlong *)(piVar3 + 0xc) = lVar5;

        piVar3[8] = (param_3 + 1) / 2 << 2;

        return piVar3;

      }

    }

    FUN_140205da0(piVar3);

  }

  return (int *)0x0;

}




