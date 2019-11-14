import React, { Component } from 'react';
import { Text, View, Image, StyleSheet, ImageBackground, TouchableOpacity } from 'react-native';

import background_img from './images/background.png';
import logo from './images/logo.png';
import title from './images/title.png';
import { api } from './config';

import lightOn1 from './images/lighton.png';
import lightOff1 from './images/lightoff.png';
import lightOn2 from './images/lighton.png';
import lightOff2 from './images/lightoff.png';
import lightOn3 from './images/lighton.png';
import lightOff3 from './images/lightoff.png';

export default class App extends React.Component {

  constructor(props)
  {
    super(props);

    this.state = {
      showLightImg1: true,
      showLightImg2: true,
      showLightImg3: true,
      warningMessage: ''
    }
  }

  _renderImage1 = () => {
    var imgSource = this.state.showLightImg1 ? lightOn1 : lightOff1;
    return (
      <Image
        style={ styles.img }
        source={ imgSource }
      />
    );
  }

  _renderImage2 = () => {
    var imgSource = this.state.showLightImg2 ? lightOn2 : lightOff2;
    return (
      <Image
        style={ styles.img }
        source={ imgSource }
      />
    );
  }

  _renderImage3 = () => {
    var imgSource = this.state.showLightImg3 ? lightOn3 : lightOff3;
    return (
      <Image
        style={ styles.img }
        source={ imgSource }
      />
    );
  }

  _executeRequest = async (route) => {

      fetch(api.URL+route, {
        method: 'POST',
        headers: {
          'Content-Type': 'application/x-www-form-urlencoded'
        }
      }).then((response) => response.json())
          .then((responseJson) => {
            this._handleResponse(responseJson);
          })
          .catch((error) => {
            this.setState({
              warningMessage: `Error: ${error}` 
            })
          });
  }

  _handleResponse = (response) => {
    if (response.status === 200){
      this.setState({
        warningMessage: `Successful request!` 
      });
    } else {
      this.setState({
        warningMessage: `Error` 
      });
    }
  };

  _onLight1Press = () => {
    this.setState({ 
        showLightImg1: !this.state.showLightImg1
    });
    this._executeRequest('/firstled');
  }

  _onLight2Press = () => {
    this.setState({ 
        showLightImg2: !this.state.showLightImg2
    });
    this._executeRequest('/secondled');
  }

  _onLight3Press = () => {
    this.setState({ 
        showLightImg3: !this.state.showLightImg3
    });
    this._executeRequest('/thirdled');
  }

  _onButtonKitchenPress = () => {
    this._executeRequest('/kitchen');
  }

  render() {
    return (
      <ImageBackground source={background_img} style={styles.rootcontainer}>
        <View style={styles.logocontainer}>
          <Image source={logo} style={styles.logo} />
          <Image source={title} style={styles.title} />
        </View>
        
        <View style={styles.lightcontainer}>
          <Text style={styles.text}> Light Kitchen </Text>
          <TouchableOpacity onPress={this._onLight1Press} 
          >
            {this._renderImage1()}
          </TouchableOpacity>
       
          <Text style={styles.text}> Light 1 </Text>
          <TouchableOpacity
              onPress={this._onLight2Press} 
          >
            {this._renderImage2()}
          </TouchableOpacity>
      
          <Text style={styles.text}> Light 2 </Text>
          <TouchableOpacity
              onPress={this._onLight3Press} 
          >
            {this._renderImage3()}
          </TouchableOpacity>
        </View>

        <TouchableOpacity style={styles.button} onPress={this._onButtonKitchenPress}>
					<Text style={styles.buttonText}>Use Kitchen</Text>
				</TouchableOpacity>

        <Text style={styles.description}>{this.state.warningMessage}</Text>
                    
      </ImageBackground>	 
    )
  }
}

const styles = StyleSheet.create({
  rootcontainer: {
    flex: 1,
    alignItems: 'center'
  },
  logocontainer: {
    flexDirection: 'row',
  },
  lightcontainer: {
    flexDirection: 'column',
    alignItems: 'center',
    justifyContent: 'flex-start'
  },
  logo: {
    marginTop: 70,
    height: 125,
    width: 125,
    marginBottom: 20
  },
  title : {
    marginTop: 40,
    height: 180,
    width: 180
  },
  text: {
    color: 'black',
    fontSize: 14,
    fontWeight: 'bold',
    textAlign: 'center',
  },
  buttonText: {
    color: 'white',
    fontSize: 24,
    fontWeight: 'bold',
    textAlign: 'center',
  },
  button: {
    width: 225,
    height: 85,
    borderRadius: 25,
    backgroundColor: "#DB4711",
    justifyContent: 'center',
    marginTop: 20,
    borderWidth: 2,
    borderColor: 'rgb(0, 0, 0)'
  },
  description: {
    marginTop: 10,
    fontSize: 16,
    color: '#ffffff',
    textAlign: 'center',
  }
});
