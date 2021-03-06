﻿using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class SimonBoard : MonoBehaviour {
	
	[Header("Buttons' Gameobjects")]
	public GameObject redButton;
	public GameObject blueButton;
	public GameObject yellowButton;
	public GameObject greenButton;
	[Header("Audio Clips")]
	public AudioClip redSound;
	public AudioClip blueSound;
	public AudioClip yellowSound;
	public AudioClip greenSound;
	[Header("Controls")]
	public float waitTime = 0.5f;
	[Header("Colors")]
	public Color red = Color.red;
	public Color redPressed;
	public Color blue = Color.blue;
	public Color bluePressed;
	public Color yellow = Color.yellow;
	public Color yellowPressed;
	public Color green = Color.green;
	public Color greenPressed;

	public static SimonBoard instance = null;

	public static SimonBoard getInstance()
	{
		return instance;
	}

	public float getWaitTime()
	{
		return this.waitTime;
	}

	void Awake()
	{
		if (instance == null)
			instance = this;
		else if (instance != this)
			Destroy (gameObject);
	}

	void Start()
	{
		redButton.GetComponent<SpriteRenderer> ().color = red;
		blueButton.GetComponent<SpriteRenderer> ().color = blue;
		yellowButton.GetComponent<SpriteRenderer> ().color = yellow;
		greenButton.GetComponent<SpriteRenderer> ().color = green;
	}


	public IEnumerator playEverythingBecauseYouLost()
	{
		GameManager.getInstance ().lockInput ();
		yield return new WaitForSeconds (2*waitTime);
		redButton.GetComponent<SpriteRenderer> ().color = redPressed;
		blueButton.GetComponent<SpriteRenderer> ().color = redPressed;
		yellowButton.GetComponent<SpriteRenderer> ().color = redPressed;
		greenButton.GetComponent<SpriteRenderer> ().color = redPressed;
		yield return new WaitForSeconds (2*waitTime);
		redButton.GetComponent<SpriteRenderer> ().color = red;
		blueButton.GetComponent<SpriteRenderer> ().color = blue;
		yellowButton.GetComponent<SpriteRenderer> ().color = yellow;
		greenButton.GetComponent<SpriteRenderer> ().color = green;
		yield return new WaitForSeconds (2*waitTime);
		redButton.GetComponent<SpriteRenderer> ().color = redPressed;
		blueButton.GetComponent<SpriteRenderer> ().color = redPressed;
		yellowButton.GetComponent<SpriteRenderer> ().color = redPressed;
		greenButton.GetComponent<SpriteRenderer> ().color = redPressed;
		yield return new WaitForSeconds (2*waitTime);
		redButton.GetComponent<SpriteRenderer> ().color = red;
		blueButton.GetComponent<SpriteRenderer> ().color = blue;
		yellowButton.GetComponent<SpriteRenderer> ().color = yellow;
		greenButton.GetComponent<SpriteRenderer> ().color = green;
		yield return new WaitForSeconds (2*waitTime);
		redButton.GetComponent<SpriteRenderer> ().color = redPressed;
		blueButton.GetComponent<SpriteRenderer> ().color = redPressed;
		yellowButton.GetComponent<SpriteRenderer> ().color = redPressed;
		greenButton.GetComponent<SpriteRenderer> ().color = redPressed;
		yield return new WaitForSeconds (2*waitTime);
		redButton.GetComponent<SpriteRenderer> ().color = red;
		blueButton.GetComponent<SpriteRenderer> ().color = blue;
		yellowButton.GetComponent<SpriteRenderer> ().color = yellow;
		greenButton.GetComponent<SpriteRenderer> ().color = green;
		yield return new WaitForSeconds (2*waitTime);
		GameManager.getInstance ().unlockInput ();
	}

	public IEnumerator playButton(int id)
	{
		switch(id)
		{
		case 0:
			redButton.GetComponent<SpriteRenderer> ().color = redPressed;
			SoundManager.getInstance ().PlaySingle (redSound);
			yield return new WaitForSeconds (waitTime);
			redButton.GetComponent<SpriteRenderer> ().color = red;
			break;
		case 1:
			blueButton.GetComponent<SpriteRenderer> ().color = bluePressed;
			SoundManager.getInstance ().PlaySingle (blueSound);
			yield return new WaitForSeconds (waitTime);
			blueButton.GetComponent<SpriteRenderer> ().color = blue;
			break;
		case 2:
			yellowButton.GetComponent<SpriteRenderer> ().color = yellowPressed;
			SoundManager.getInstance ().PlaySingle (yellowSound);
			yield return new WaitForSeconds (waitTime);
			yellowButton.GetComponent<SpriteRenderer> ().color = yellow;
			break;
		case 3:
			greenButton.GetComponent<SpriteRenderer> ().color = greenPressed;
			SoundManager.getInstance ().PlaySingle (greenSound);
			yield return new WaitForSeconds (waitTime);
			greenButton.GetComponent<SpriteRenderer> ().color = green;
			break;
		}
	}

	public IEnumerator playSequence(List<int> sequence)
	{
		yield return new WaitForSeconds (2*waitTime);
		for (int i = 0; i < sequence.Count; i++) 
		{
			switch(sequence[i])
			{
			case 0:
				redButton.GetComponent<SpriteRenderer> ().color = redPressed;
				SoundManager.getInstance ().PlaySingle (redSound);
				yield return new WaitForSeconds (waitTime);
				redButton.GetComponent<SpriteRenderer> ().color = red;
				break;
			case 1:
				blueButton.GetComponent<SpriteRenderer> ().color = bluePressed;
				SoundManager.getInstance ().PlaySingle (blueSound);
				yield return new WaitForSeconds (waitTime);
				blueButton.GetComponent<SpriteRenderer> ().color = blue;
				break;
			case 2:
				yellowButton.GetComponent<SpriteRenderer> ().color = yellowPressed;
				SoundManager.getInstance ().PlaySingle (yellowSound);
				yield return new WaitForSeconds (waitTime);
				yellowButton.GetComponent<SpriteRenderer> ().color = yellow;
				break;
			case 3:
				greenButton.GetComponent<SpriteRenderer> ().color = greenPressed;
				SoundManager.getInstance ().PlaySingle (greenSound);
				yield return new WaitForSeconds (waitTime);
				greenButton.GetComponent<SpriteRenderer> ().color = green;
				break;
			}
			if(i < (sequence.Count-1)) yield return new WaitForSeconds (waitTime);
		}
		GameManager.getInstance ().unlockInput ();
	}
}
