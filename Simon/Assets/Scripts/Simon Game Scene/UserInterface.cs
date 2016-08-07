using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class UserInterface : MonoBehaviour {

	public static UserInterface instance = null;

	public Text sequenceSizeText;

	public static UserInterface getInstance()
	{
		return instance;
	}

	void Awake()
	{
		if (instance == null)
			instance = this;
		else if(instance != this)
			Destroy (gameObject);
	}

	void Update()
	{
		if(!GameManager.getInstance().isGameOver()) sequenceSizeText.text = "" + (GameManager.getInstance ().getSequenceSize ()-1);
	}

	public void TurnGameOffPlease()
	{
		sequenceSizeText.text = "OFF";
	}
}
