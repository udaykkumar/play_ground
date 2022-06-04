import pyautogui
import time


def start():
	print("starting mouse move ..")

	while True:
		print("Waiting before move", end=' ')
		for _ in range(120):
			print(".", end=' ')
			time.sleep(2)

		print("\nmove .. ")
		#pyautogui.click(100, 100)
		pyautogui.moveTo(100, 150)
		pyautogui.moveRel(0, 10)  # move mouse 10 pixels down
		pyautogui.dragTo(100, 150)
		pyautogui.dragRel(0, 10)  # drag mouse 10 pixels down
		time.sleep(1)
if __name__ == '__main__':
    start()