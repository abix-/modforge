// Address: 0x140025560
// Ghidra name: FUN_140025560
// ============ 0x140025560 FUN_140025560 (size=143) ============


undefined8 * FUN_140025560(undefined8 *param_1,ulonglong param_2)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  

  *param_1 = TiXmlElement::vftable;

  FUN_1400255f0();

  FUN_140027260(param_1 + 0xd);

  *param_1 = TiXmlNode::vftable;

  puVar2 = (undefined8 *)param_1[5];

  while (puVar2 != (undefined8 *)0x0) {

    puVar1 = (undefined8 *)puVar2[0xc];

    (**(code **)*puVar2)(puVar2,1);

    puVar2 = puVar1;

  }

  FUN_140027900(param_1 + 7);

  *param_1 = TiXmlBase::vftable;

  if ((param_2 & 1) != 0) {

    FUN_1402c7088(param_1,0xd8);

  }

  return param_1;

}




