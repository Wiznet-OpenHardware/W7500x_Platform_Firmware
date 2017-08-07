/*
 * phy.h
 *
 *  Created on: Aug 4, 2017
 *      Author: Kei
 */

#ifndef SRC_HW_BOARD_PHY_H_
#define SRC_HW_BOARD_PHY_H_

void initPHY(void);

void initPHYLinkInputPin(void);
uint8_t getPHYLinkInputState(void);

#endif /* SRC_HW_BOARD_PHY_H_ */
