// Address: 0x1401300a0
// Ghidra name: FUN_1401300a0
// ============ 0x1401300a0 FUN_1401300a0 (size=352) ============


uint FUN_1401300a0(longlong *param_1,ulonglong param_2)



{

  byte bVar1;

  byte *pbVar2;

  uint uVar3;

  

  pbVar2 = (byte *)*param_1;

  if (param_2 != 0) {

    bVar1 = *pbVar2;

    if (bVar1 != 0) {

      if (-1 < (char)bVar1) {

        *param_1 = (longlong)(pbVar2 + 1);

        return (uint)bVar1;

      }

      if (((bVar1 & 0xe0) == 0xc0) && (1 < param_2)) {

        if (((pbVar2[1] & 0xc0) == 0x80) &&

           (uVar3 = pbVar2[1] & 0x3f | (bVar1 & 0x1f) << 6, 0x7f < uVar3)) {

          *param_1 = (longlong)(pbVar2 + 2);

          return uVar3;

        }

      }

      else if (((bVar1 & 0xf0) == 0xe0) && (2 < param_2)) {

        if ((((pbVar2[1] & 0xc0) == 0x80) && ((pbVar2[2] & 0xc0) == 0x80)) &&

           ((uVar3 = (pbVar2[1] & 0x3f | (bVar1 & 0xf) << 6) << 6 | pbVar2[2] & 0x3f, 0x7ff < uVar3

            && (0x7ff < uVar3 - 0xd800)))) {

          *param_1 = (longlong)(pbVar2 + 3);

          return uVar3;

        }

      }

      else if ((((((bVar1 & 0xf8) == 0xf0) && (3 < param_2)) && ((pbVar2[1] & 0xc0) == 0x80)) &&

               (((pbVar2[2] & 0xc0) == 0x80 && ((pbVar2[3] & 0xc0) == 0x80)))) &&

              (uVar3 = ((pbVar2[1] & 0x1f | (bVar1 & 7) << 6) << 6 | pbVar2[2] & 0x3f) << 6 |

                       pbVar2[3] & 0x3f, 0xffff < uVar3)) {

        *param_1 = (longlong)(pbVar2 + 4);

        return uVar3;

      }

      *param_1 = (longlong)(pbVar2 + 1);

      return 0xfffd;

    }

  }

  return 0;

}




